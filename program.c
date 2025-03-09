/*
 * clang --target=wasm32 -nostdlib -o program.wasm -Wl,--no-entry program.c
 */

#include <stdint.h>

#define WASM_EXPORT(n) __attribute__((export_name(#n), used, visibility("default"))) n
#define WASM_IMPORT(n) __attribute__((import_module("env"), import_name(#n))) n

void WASM_IMPORT(printxy)(int32_t x, int32_t y, const char *s);

int WASM_EXPORT(main)(void)
{
	printxy(0, 0, "hello world from WebAssembly!");
	return 69;
}
