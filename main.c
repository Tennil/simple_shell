#include "main.h"

/**
 * f - function that creates a new process
 * @array: array of arguments
 * @env: array of environment variables
 * @str: string to be freed
 * @av: args vector array
 * @strCpy: copy of string to be freed
 * @nCmds: number of commands executed
 * Return: 0 success , -1 on error
 */
int f(char **array, char **env, char **av, char *str, char *strCpy, int nCmds)
{
	pid_t pid;
	struct stat statuses;
	int sig;
	char *command = NULL;

	if (_inBuilt(array, env, str, strCpy, nCmds) == 0)
		return (0);
	pid = fork();
	if (pid == -1)
	{
		write(STDOUT_FILENO, "forking error", 13);
		return (-1);
	}
	if (pid == 0)
	{
		if (array[0][0] == '/')
		{
			if (stat(array[0], &statuses) == -1)
				error_hand(av, array, nCmds, str, strCpy);
			if (access(array[0], X_OK) == -1)
				error_hand(av, array, nCmds, str, strCpy);
			execve(array[0], array, NULL);
		}
		else
		{
			command = _pathHandler(array[0], env);
			if (command == NULL)
				error_hand(av, array, nCmds, str, strCpy);
			else
				execve(command, array, NULL);
		}
	}
	else
	{
		wait(&sig);
	}
	return (0);
}

/**
 * _inBuilt - checks if command is built-in
 * @array: array of arguments
 * @env: array of environment variables
 * @str: string to be freed
 * @strCpy: copy of string to be freed
 * @nCmds: number of commands executed
 *
 * Return: 1 if command is not built-in, 0 otherwise
 */
int _inBuilt(char **array, char **env, char *str, char *strCpy, int nCmds)
{
	if (array == NULL || env == NULL || *array == NULL || *env == NULL)
		return (1);
	if (_strcmp(array[0], "exit") == 0)
		return (_inExit(array, str, strCpy, nCmds));
	if (_strcmp(array[0], "env") == 0)
		return (_pEnv(env));
	return (1);
}

/**
 * _empty_checker - checks if input string contains non-alpha chars
 * @str: the string input
 * Return: 1 if isalpha 0 otherwise
*/
int _empty_checker(char *str)
{
	int i = 0;
	int checker = 0;

	while (str[i])
	{
		if (_isalpha(str[i]))
		{
			checker++;
		}
		i++;
	}
	if (checker > 0)
		return (1);
	else
		return (0);
}

/**
 * main - function that initializes simple shell
 * @ac: argument count of the shell
 * @av: argument vector of the shell
 * @env: environment of the shell
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	char *str, *strCpy, **array;
	int nCmds = 0;
	ssize_t rVal;
	size_t n = 0;

	(void)ac;
	(void)av;
	while (1)
	{
		n = 0;
		str = NULL;
		strCpy = NULL;
		nCmds++;
		if (isatty(STDIN_FILENO) == 1)
			_prompt();
		signal(SIGINT, control_c);
		rVal = get_line(&str, &n, stdin);
		if (rVal == -1 || rVal == EOF)
			return (control_d(str));
		if (str[0] == '\n' || (_empty_checker(str)) == 0)
		{
			free(str);
			continue;
		}
		str[_strcspn(str, "\n")] = '\0';
		strCpy = rea_lloc(str);
		_strcpy(strCpy, str);
		array = _tokenize(strCpy);
		if (array == NULL)
		{
			free(str);
			free(strCpy);
			return (0);
		}
		f(array, env, av, str, strCpy, nCmds);
		_memfree(array, str, strCpy);
	}
	return (0);
}
