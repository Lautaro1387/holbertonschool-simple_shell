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
		buff = strtok(buff, "\n\t\r");
		args[0] = strdup(buff);
		if (fork() == 0)
		{
			if ((args[0][0] != ' ') && (args[0][_strlen(args[0]) != ' ']) && execve(args[0], args, NULL) == -1)
			{
				perror("Error");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
		i++;
		free(args[0]);
	}
	free(buff);
	return (0);
}
