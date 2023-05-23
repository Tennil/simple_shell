#include "main.h"

/**
 * _getenv - finds value of an environment variable
 * @var: name of environment variable to find
 * @env: array of environment variables
 *
 * Return: pointer to value of variable, or NULL if not found
 */
char *_getenv(char *var, char **env)
{
	int i = 0;
	int var_len = _slen(var);

	if (var == NULL || env == NULL || *env == NULL)
		return (NULL);

	while (env[i] != NULL)
	{
		if (_strn_cmp(var, env[i], var_len) == 0 && env[i][var_len] == '=')
			return (&(env[i][var_len + 1]));
		i++;
	}
	write(STDOUT_FILENO, "env var not found!", 18);
	return (NULL);
}
