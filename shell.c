#include "main.h"
int _strlen(char *s);
/**
*
*
*
*
*/

int main(void)
{
	int status;
	int i = 0;
	char *args[] = {"", NULL};
	size_t len = 0;
	char *buff = NULL;

	while (1)
	{
		if (getline(&buff, &len, stdin) == -1)
			break;
		buff = strtok(buff, "\t\n\r");
		args[0] = strdup(buff);
		while (buff)
		{
			args[len] = buff;
			buff = strtok(NULL, "\t\n\r");
		}
		args[len] = NULL;
		if (fork() == 0)
		{
			if ((args[0][0] != ' ') && (args[0][_strlen(args[0])] != ' ') && execve(args[0], args, NULL) == -1)
			{
				perror("Error");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
		free(args[0]);
	}
	free(buff);
	return (0);
}
int _strlen(char *s)
{
	int i = 0;
	while (*s == '\0')
	{
		i++;
		s++;
	}
	return (i);
}
