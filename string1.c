#include "main.h"

/**
 * _strcat- appends scr to dest string
 * @dest: the string to append to
 * @src: the string to append from
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;
	int len = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
		len++;
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[len++] = src[j];
	}
	return (dest);
}

/**
 * _str_cat - uses malloc to cat
 * @s1: the first string
 * @s2: the second string
 * Return: the string
 */
char *_str_cat(char *s1, char *s2)
{
	int len1 = _slen(s1);
	int len2 = _slen(s2);

	char *result = malloc(len1 + len2 + 1);

	if (result == NULL)
		return (NULL);
	_bytecpy(result, s1, len1);
	_bytecpy(result + len1, s2, len2 + 1);
	return (result);
}

/**
 * _strcmp- compares two strings
 * @s1: the first string to compare
 * @s2: the second string ro compare
 * Return: count
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int count = 0;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] > s2[i])
		{
			count = s1[i] - s2[i];
			break;
		}
		else if (s1[i] < s2[i])
		{
			count = s1[i] - s2[i];
			break;
		}
		else
		{
			count = 0;
		}
	}
	return (count);
}

/**
 * *_strcpy- copies one string into another
 * @src: the string to be copied
 * @dest: the string to be copied to
 * Return: *dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup-  duplicates string input to memory with malloc
 * @str: the string it recieves
 * Return: pstr
 */
char *_strdup(char *str)
{
	int i;
	int len = 0;
	char *pstr;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		len++;
	pstr = malloc((len + 1) * (sizeof(char)));
	if (pstr == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		pstr[i] = str[i];
	pstr[i] = '\0';
	return (pstr);
}
