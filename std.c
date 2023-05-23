#include "main.h"

/**
 * _atoi - convert a string to an integer.
 * @s: the string to be comverted.
 *
 *Return: The integer value of the comverted string.
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do {

		if (*s == '-')
			sign *= -1;

		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');

		else if (num > 0)
			break;
	} while (*s++);

	return (num * sign);
}

/**
 * _pint - prints an int
 * @number: num to change to str
 * Return: no. of characters on STDOUT
 */

char *_pint(int number)
{
	int tenth = 1;
	int k = 0;
	int tenth_int = number;
	char *int_ger;

	int_ger = malloc(34);
	if (int_ger == NULL)
		return (NULL);
	if (number == 0)
	{
		int_ger[k] = 0 + '0';
		return (int_ger);
	}
	number = number / 10;

	while (tenth != 0)
	{
		int_ger[k] = (tenth_int / tenth) + '0';
		tenth_int = tenth_int % tenth;
		tenth /= 10;
		k++;
	}
	int_ger[k] = '\0';
	return (int_ger);
}

/**
 * _putchar - writes a character c to standard output
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts- prints a string to stdout
 * @str: the string it recieves
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _isalpha- checks whether input is alphabet
 * @c: input it recieves
 * Return: 1 if true. 0 if false
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
		return (1);
	else
		return (0);
}
