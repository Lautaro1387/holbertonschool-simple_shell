#include "main.h"
/**
*
*
*
*
*/

int main(__attribute__((unused))int ac, char **av)
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
			if (check_space(buff))
			{
				status = _stat(args[0], av[0]);
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
int check_space(char *buff)
{
	int i = 0;

	while (buff[i])
	{
		if (buff[i] != ' ' && buff[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
