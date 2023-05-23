#include "main.h"
/**
 * _pathHandler - Searches for a file in the directories listed in the PATH
 * environment variable
 * @s: Name of the file to search for
 * @env: Pointer to an array of environment variables
 *
 * Return: On success, a pointer to a string containing the full path of the
 * found file. On failure, NULL.
 */
char *_pathHandler(char *s, char **env)
{
	char *cant, *route;
	paths_list *lists, *temp;
	struct stat mk;

	if (s == NULL || env == NULL || *env == NULL)
		return (NULL);
	route = _getenv("PATH", env);
	if (route == NULL)
	{
		write(STDERR_FILENO, "No path available", 17);
		_exit(0);
	}
	lists = _develop_linkedlist(route);
	if (lists == NULL)
	{
		write(STDERR_FILENO, "faulty path", 11);
		_exit(0);
	}
	lists = _append_node(route, lists);
	temp = lists;
	while (temp != NULL)
	{
		if (route[0] == ':')
			cant = _str_cat("./", s);
		else
			cant = _str_cat(temp->dir, s);
		if (cant == NULL)
			return (NULL);
		if (stat(cant, &mk) == 0 && access(cant, X_OK) == 0)
		{
			list_free(lists);
			return (cant);
		}
		temp = temp->next;
		free(cant);
	}
	list_free(lists);
	return (NULL);
}

/**
 * _develop_linkedlist - Creates a new linked list of paths_list nodes
 * @s: String to parse and create the linked list from
 *
 * Return: On success, a pointer to the head of the linked list.
 *         On failure, NULL.
 */
paths_list *_develop_linkedlist(char *s)
{
	int num_nodes = 1, i = 0;
	paths_list *last, *head, *temp, *new_node;

	temp = malloc(sizeof(paths_list));
	if (temp == NULL)
		return (NULL);
	head = temp;
	last = malloc(sizeof(paths_list));
	if (last == NULL)
	{
		free(temp);
		return (NULL);
	}
	last->next = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == ':')
			num_nodes++;
		i++;
	}
	while ((num_nodes - 2) > 0)
	{
		new_node = malloc(sizeof(paths_list));
		if (new_node == NULL)
		{
			free(temp);
			free(last);
			return (NULL);
		}
		temp->next = new_node;
		temp = temp->next;
		num_nodes--;
	}
	temp->next = last;
	return (head);
}


/**
 * _append_node - Appends a directory path to each node in a linked list
 * @s: String to parse and append to each node in the linked list
 * @lists: Pointer to the head of the linked list
 *
 * Return: On success, a pointer to the head of the linked list.
 *         On failure, NULL.
 */
paths_list *_append_node(char *s, paths_list *lists)
{
	char *directory;
	paths_list *pointer, *head;
	int i = 0, j = 0, sup = 0, dir_len = 0;

	if (s == NULL || lists == NULL)
		return (NULL);
	head = lists;
	pointer = head;
	while (pointer != NULL)
	{
		if (s[i] == ':' || s[i] == '\0')
		{
			if (s[i] != '\0')
				i++;
			directory = malloc(sizeof(char) * (dir_len + 2));
			if (directory == NULL)
				return (NULL);
			while (s[sup] != ':' && s[sup] != '\0')
			{
				directory[j] = s[sup];
				sup++;
				j++;
			}
			directory[j++] = '/';
			directory[j] = '\0';
			sup = i;
			j = 0;
			pointer->dir = directory;
			pointer = pointer->next;
		}
		else
		{
			dir_len++;
			i++;
		}
	}
	return (head);
}

/**
 * list_free - frees alinked list
 * @h: head of linked list
 * Return: nothing
 */
void list_free(paths_list *h)
{
	paths_list *nextnod;

	while (h != NULL)
	{
		nextnod = h->next;
		free(h->dir);
		free(h);
		h = nextnod;
	}
}
