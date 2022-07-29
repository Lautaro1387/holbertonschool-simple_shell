#include "main.h"

extern char **environ;

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
		buff = strtok(buff, "\n");
		args[0] = strdup(buff);
		if (fork() == 0)
		{
			if (execve(args[0], args, NULL) == -1)	
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
