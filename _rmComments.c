#include "main.h"
/**
 * _rmComments - removes comments from input string
 * * @o_str: the string input
 * * Return: n_str without comments
 */
char *_rmComments(char *o_str)
{
	int i = 0;
	char *n_str = malloc(strlen(o_str) + 1);
	int j = 0;

	if (n_str == NULL || o_str[0] == '#')
		return (NULL);
	while (o_str[i] != '\0')
	{
		if (o_str[i] == ' ' && o_str[i + 1] == '#')
		{
			i++;
			while (o_str[i] != '\0' && o_str[i] != '\n')
			i++;
		}
		else
		{
			n_str[j] = o_str[i];
			j++;
		}
		i++;
	}
	n_str[j] = '\0';
	free(o_str);
	return (n_str);
}
