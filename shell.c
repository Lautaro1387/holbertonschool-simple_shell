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
	char *args[] = {"", NULL};
	size_t len = 0;
	char *buff = NULL;

	while (1)
	{
		if (getline(&buff, &len, stdin) == -1)
			break;
		buff = strtok(buff, "\t\n\r");
		args[0] = strdup(buff);
		if (fork() == 0)
		{
		if ((args[0][0] != ' ') && (args[0][_strlen(args[0])] != ' '))
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
				return (1);
			}
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
	int z = 0;

	while (*s == '\0')
	{
		z++;
		s++;
	}
	return (z);
}
