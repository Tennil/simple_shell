#include "main.h"

/**
 * _sCmp - Checks if a character is a delimiter.
 * @c: The character to check.
 * @delim: The string of delimiters.
 *
 * Return: true if the character is a delimiter, false otherwise.
 */
int _sCmp(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - Tokenizes a string based on delimiters.
 * @str: The string to tokenize.
 * @delim: The string of delimiters.
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found.
 */
char *_strtok(char *str, char *delim)
{
	static char *mem;
	char *token = NULL;

	if (!str)
		str = mem;

	if (!str)
		return (NULL);


	while (*str != '\0' && _sCmp(*str, delim))
		str++;

	if (*str == '\0')
		return (NULL);

	token = str;
	while (*str != '\0')
	{
		if (_sCmp(*str, delim))
		{
			*str = '\0';
			mem = str + 1;
			return (token);
		}
		str++;
	}
	mem = str;
	return (token);
}
