
#include <stdio.h>

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>

#include "wasm3.h"

PSP_MODULE_INFO("psp-wasm3-test", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);

#include "program.wasm.h"

static IM3Environment m3_env = NULL;
static IM3Runtime m3_runtime = NULL;
static IM3Module m3_module = NULL;
static IM3Function m3_function = NULL;

static int exit_callback(int arg1, int arg2, void *common)
{
	if (m3_runtime)
		m3_FreeRuntime(m3_runtime);

	if (m3_env)
		m3_FreeEnvironment(m3_env);

	m3_env = NULL;
	m3_runtime = NULL;

	sceKernelExitGame();
	return 0;
}

static int update_thread(SceSize args, void *argp)
{
	int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
	sceKernelRegisterExitCallback(cbid);
	sceKernelSleepThreadCB();
	return 0;
}

static int setup_callbacks(void)
{
	int thid = sceKernelCreateThread("Update Thread", update_thread, 0x11, 0xFA0, 0, 0);
	if (thid >= 0)
		sceKernelStartThread(thid, 0, 0);
	return thid;
}

m3ApiRawFunction(printxy)
{
	m3ApiGetArg(int32_t, x);
	m3ApiGetArg(int32_t, y);
	m3ApiGetArgMem(const char *, s);
	pspDebugScreenSetXY(x, y);
	pspDebugScreenPrintf(s);
	m3ApiSuccess();
}

int main(void)
{
	M3Result res;

	// setup psp callbacks
	setup_callbacks();

	// init debug screen
	pspDebugScreenInit();

	// setup environment
	m3_env = m3_NewEnvironment();
	if (!m3_env)
		return 1;

	// setup runtime
	m3_runtime = m3_NewRuntime(m3_env, 8192, NULL);
	if (!m3_runtime)
		return 1;

	// parse module
	res = m3_ParseModule(m3_env, &m3_module, program_wasm, program_wasm_len);
	if (res)
	{
		printf("m3_ParseModule(): %s\n", res);
		return 1;
	}

	// load module
	res = m3_LoadModule(m3_runtime, m3_module);
	if (res)
	{
		printf("m3_LoadModule(): %s\n", res);
		return 1;
	}

	// load system functions
	res = m3_LinkRawFunction(m3_module, "env", "printxy", "v(iii)", printxy);
	if (res)
	{
		printf("m3_LinkRawFunction(): %s\n", res);
		return 1;
	}

	// find main
	res = m3_FindFunction(&m3_function, m3_runtime, "main");
	if (res)
	{
		printf("m3_FindFunction(): %s\n", res);
		return 1;
	}

	// main loop
	while (1)
	{
		// call main every frame
		res = m3_CallV(m3_function);
		if (res)
		{
			printf("m3_CallV(): %s\n", res);
			return 1;
		}

		sceDisplayWaitVblankStart();
	}

	return 0;
}
