#include "main.h"
#define S_DELIM " \t\0"

/**
 * _tokenize - tokenizes the string
 * @str: string to be tokenized
 * Return: array of tokens
 */

char **_tokenize(char *str)
{
	int i = 0;
	char *temp;
	char *cpStr;
	int items = 0;
	char **array;

	while (str[i])
	{
		if (str[i] != ' ' &&
			(str[i + 1] == ' ' ||
			str[i + 1] == '\0' ||
			str[i + 1] == '\t'))
			items++;
		i++;
	}

	array = malloc(sizeof(char *) * (items + 1));
	if (array == NULL)
		return (NULL);
	temp = _strtok(str, S_DELIM);
	i = 0;
	while (temp != NULL)
	{
		cpStr = _strdup(temp);
		if (cpStr == NULL)
		{
			free(array);
			return (NULL);
		}
		array[i] = cpStr;
		temp = _strtok(NULL, S_DELIM);
		i++;
	}
	array[i] = NULL;
	return (array);
}
