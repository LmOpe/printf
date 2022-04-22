#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE (1024)
#define VAL_SPEC ("csdif%b")

int _printf(const char *format, ...);
int count_specifiers(const char *s);
int get_next_spec(const char *s);
void get_specifiers(const char *s, int n, char *dst);
int print_string(va_list *v);
int print_char(va_list *v);
int print_double(va_list *v);
int print_dec(va_list *v);
int print_int(va_list *v);
int print_perct(va_list *v);
int _putchar(char);
int int_toa(char *dst, int i);
int float_toa(char *dst, double f, int precision);
int _pow(int a, int n);
int _strlen(const char *s);
int valid_spec(char c);
int print_to(const char *s, int start, int end);
int search_spec(const char *s, int n);
int _itob(char *dst, unsigned int a);
int print_bin(va_list *v);
#endif
