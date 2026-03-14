#ifndef variadic_functions_h
#define variadic_functions_h

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void print_char(va_list args);
void print_int(va_list args);
void print_string(va_list args);
void print_float(va_list args);

/**
 * struct type_print - struct for matching types with print functions
 * @type: format specifier
 * @print_type: pointer to the corresponding printing function
 */
typedef struct type_print
{
	char type;
	void (*print_type)(va_list);
} type_print;

#endif

