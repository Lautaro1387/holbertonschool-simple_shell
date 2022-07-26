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
char *_which(char *av);
int _specstr(char *token, char **envi);
int pathverify(char *args);
int created_fork(char **args, char **env);
char *_getenv(const char *name);
char *token_checker(char *buff, char **array, char *delim);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
#endif
