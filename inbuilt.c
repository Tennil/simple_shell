#include "main.h"
/**
 * _inExit - exits the shell
 * @array: array of arguments
 * @str: string to be freed
 * @strCpy: copy of string to be freed
 * @nCmds: number of commands executed
 * Return: 0 on success
 */

int _inExit(char **array, char *str, char *strCpy, int nCmds)
{
	int i, j;
	char *num;

	j = 0;
	if (array[1] == NULL)
	{
		_memfree(array, str, strCpy);
		exit(1);
	}
	else
	{
		i = _atoi(array[1]);
		if (i == -1)
		{
			num = _pint(nCmds);
			write(STDERR_FILENO, array[0], 7);
			write(STDERR_FILENO, num, _slen(num));
			write(STDERR_FILENO, ": exit: command not found!: ", 28);
			while (array[1][j] != '\0')
				j++;
			write(STDOUT_FILENO, array[1], j);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		_memfree(array, str, strCpy);
		_exit(i);
	}
}
