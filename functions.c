#include "main.h"
#include <stdio.h>

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

