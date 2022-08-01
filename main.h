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
int check_space(char *buff);
int stat_checker(char *ac, char *av);
int _which(int argc, char **argv);
void _puts(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
#endif
