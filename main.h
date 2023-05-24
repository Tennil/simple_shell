#ifndef HEADER_H
#define HEADER_H

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct paths - structure for PATH variables
 * @dir: directory to search
 * @next: pointer to the next node
 */

typedef struct paths
{
	char *dir;
	struct paths *next;
} paths_list;

int _putchar(char c);
char *_strtok(char *str, char *delim);
int _sCmp(char s, char *delim);
int f(char **array, char **env, char **av, char *str, char *strCpy, int nCmds);
void list_free(paths_list *h);
int _strcspn(const char *s, const char *reject);
int _inBuilt(char **array, char **env, char *str, char *strCpy, int nCmds);
paths_list *_append_node(char *s, paths_list *lists);
paths_list *_develop_linkedlist(char *s);
char *_pathHandler(char *s, char **env);
char *_str_cat(char *s1, char *s2);
char *_bytecpy(char *dest, char *src, unsigned int n);
char **_split_paths(char *str, int num_paths);
int _count_paths(char *str);
char *_get_path(char **env);
void _puts(char *str);
void _prompt(void);
void _read(size_t *n, char *str);
int _slen(char *str);
char **_tokenize(char *str);
int _atoi(char *s);
char *_pint(int number);
int _inExit(char **array, char *str, char *strCpy, int nCmds);
char *_getenv(char *var, char **env);
int _pEnv(char **env);
char *_strdup(char *str);
void error_hand(char **argv, char **array, int nCmds, char *str, char *strCpy);
void _memfree(char **array, char *str, char *strCpy);
void _array_free(char **array);
void control_c(int sig);
int control_d(char *str);
char *rea_lloc(char *d);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strn_cmp(char *s1, char *s2, size_t n);
char *_strcat(char *dest, char *src);
char *_input(void);
char *_memset(char *s, char b, unsigned int n);
char *_strdup(char *str);
ssize_t get_line(char **str, size_t *n, FILE *stream);
void b_line(char **str, size_t *n, char *buff, size_t j);
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size);
void mem_cpy(void *newptr, const void *ptr, unsigned int size);
int _isalpha(int c);
int _empty_checker(char *str);
char *_rmComments(char *o_str);

#endif
