#ifndef PRE_SHELL
#define PRE_SHELL
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <sys/file.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
extern char **environ;
char *check_space(char *buff);
char *_which(char *av);
int stat_checker(char *args);
int _specstr(char *token, int str, char **env);
char *_getenv(const char *name);
char *token_checker(char *buff, char **array, char *delim);
void _puts(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
#endif
