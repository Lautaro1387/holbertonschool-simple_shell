#include "main.h"

extern char **environ;

/**
*
*
*
*
*/

int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	int status;
	int i = 0;
	char *args[] = {"", NULL};
	size_t len = 0;
	char *buff = NULL;

	while (1 && env[i])
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
<<<<<<< HEAD
		i++;
=======
		free(args[0]);
>>>>>>> f20890b111f29f4be89361813fb1f778dd46bb0a
	}
	free(buff);
	return (0);
}
