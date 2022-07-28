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
	char *buff;
	size_t len = 0;

	while (_strcmp(buff, "exit") != 0)
	{
		printf("#cisfun$ ");
		getline(&buff, &len, stdin);
		buff = strtok(buff, "\n");
		args[0] = strdup(buff);
		if (fork() == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		else
		{
			wait(&status);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
