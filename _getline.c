#include "main.h"

#define B_SIZE 1024

/**
 * b_line - assigns the line var for get_line
 * @str: Buffer that store the input str
 * @buff: str that is been called to line
 * @n: size of line
 * @j: size of buff
 */
void b_line(char **str, size_t *n, char *buff, size_t j)
{

	if (*str == NULL)
	{
		if  (j > B_SIZE)
			*n = j;

		else
			*n = B_SIZE;
		*str = buff;
	}
	else if (*n < j)
	{
		if (j > B_SIZE)
			*n = j;
		else
			*n = B_SIZE;
		*str = buff;
	}
	else
	{
		_strcpy(*str, buff);
		free(buff);
	}
}
/**
 * get_line - Read inpt from stream
 * @str: buff that stores the input
 * @n: size of str
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_line(char **str, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t rVal;
	char *buff;
	char last = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buff = malloc(sizeof(char) * B_SIZE);
	if (buff == 0)
		return (-1);
	while (last != '\n')
	{
		i = read(STDIN_FILENO, &last, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buff);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= B_SIZE)
			buff = _realloc(buff, input, input + 1);
		buff[input] = last;
		input++;
	}
	buff[input] = '\0';
	b_line(str, n, buff, input);
	rVal = input;
	if (i != 0)
		input = 0;
	return (rVal);
}
