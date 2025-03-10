/*
 * clang --target=wasm32 -nostdlib -Os -o program.wasm -Wl,--no-entry program.c
 */

#include <stdint.h>

#define WASM_EXPORT(n) __attribute__((export_name(#n), used, visibility("default"))) n
#define WASM_IMPORT(n) __attribute__((import_module("env"), import_name(#n))) n

void WASM_IMPORT(printxy)(int32_t x, int32_t y, const char *s);

void itos(int num, char *str)
{
	int i = 0;

	int sign = num;

	if (num < 0)
		num = -num;

	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}

	if (sign < 0)
		str[i++] = '-';

	str[i] = '\0';

	for (int j = 0, k = i - 1; j < k; j++, k--)
	{
		char temp = str[j];
		str[j] = str[k];
		str[k] = temp;
	}
}

int fib(int n)
{
	if (n < 2)
		return n;
	return fib(n - 1) + fib(n - 2);
}

int WASM_EXPORT(main)(void)
{
	char msg[64];

	int res = fib(15);

	itos(res, msg);

	printxy(0, 0, msg);

	return res;
}
