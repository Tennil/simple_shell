#include "main.h"

/**
 * _pEnv - prints the environment variables
 * @env: array of environment variables
 *
 * Return: 0 on success, or -1 on error
 */
int _pEnv(char **env)
{
	int i = 0;
	size_t len = 0;

	if (env == NULL)
		return (-1);

	while (env[i] != NULL)
	{
		len = _slen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (0);
}
