#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int count_digits(int n);

/**
* _printf - A simplified version of printf.
* @format: The format string.
* @...: Variable number of arguments.
*
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
int count = 0;
va_list args;

va_start(args, format);
while (format && *format)
{
if (*format != '%')
{
_putchar(*format);
count++;
}
else
{
format++;
if (*format == 'c')
{
_putchar(va_arg(args, int));
count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
if (str)
{
while (*str)
{
_putchar(*str);
str++;
count++;
}
}
else
{
fputs("(null)", stdout);
count += 6;
}
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
printf("%d", num);
count += num < 0 ? count_digits(-num) + 1 : count_digits(num);
}
else if (*format == '%')
{
_putchar('%');
count++;
}
else if (*format == '\0')
{
break;
}
}
format++;
}
va_end(args);
return (count);
}

/**
* count_digits - Counts the number of digits in an integer.
* @n: The integer to count digits.
*
* Return: The number of digits in the integer.
*/
int count_digits(int n)
{
int count = 0;
while (n != 0)
{
n /= 10;
count++;
}
return (count);
}
