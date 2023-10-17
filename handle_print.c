#include "main.h"
#include <stdio.h>
#include <stdarg.h>

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

