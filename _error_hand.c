#include "main.h"

/**
 * error_hand - Dealing with errors
 * @argv: argument vector
 * @array: pointer to token array from user
 * @nCmds: number of cmd inputs
 * @str: user line input
 * @strCpy: user input lacking '\n' character
 */
void error_hand(char **argv, char **array, int nCmds, char *str, char *strCpy)
{
	char *s;

	s = _pint(nCmds);
	write(STDERR_FILENO, argv[0], _slen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, s, _slen(s));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, array[0], _slen(array[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
	free(s);
	_memfree(array, str, strCpy);
	exit(EXIT_SUCCESS);
}

/**
 * _memfree - frees all var used
 * @str: user input
 * @strCpy: user input without newline
 * @array: double pointer to argument array
 */

void _memfree(char **array, char *str, char *strCpy)
{
	_array_free(array);
	free(str);
	free(strCpy);
	free(array);
}

/**
 * _array_free - frees the array
 * @array: double pointer to tokens for freeing
 */

void _array_free(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
}
