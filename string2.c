#include "main.h"

/**
 * _slen - Calculates the length of a string.
 *
 * @str: Pointer to the string.
 *
 * Return: The length of the string.
 */
int _slen(char *str)
{
	int slen = 0;

	while (str[slen])
	{
		slen++;
	}
	return (slen);
}

/**
 * _strn_cmp - compares two strings for the 1st n bytes
 * @s1: string to be compared
 * @s2: string to be compared
 * @n: number of bytes to be compared
 * Return: 0 on success and -1 on error
 */
int _strn_cmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			if (_slen(s1) == _slen(s2))
			{
				return (0);
			}
			else if (_slen(s1) < _slen(s2))
			{
				return (-1);
			}
			else
			{
				return (1);
			}
		}
		else if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/**
 * _strcspn - gets the length of a prefix substring.
 * @s: string to be scanned.
 * @reject: string containing the characters to match.
 *
 * Return: The length of the initial segment of s which does not contain any
 * of the characters in reject.
 */
int _strcspn(const char *s, const char *reject)
{
	const char *p, *spanp;
	char c, sc;

	for (p = s;;)
	{
		c = *p++;
		spanp = reject;
		do {
			sc = *spanp++;
			if (sc == c)
			{
				return (p - 1 - s);
			}
		} while (sc != 0);
	}
}
