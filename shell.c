#include "main.h"
/**
*
*
*
*
*/

int main(__attribute__((unused))int ac, char **av)
{
	int status = 0;
	char *args[] = {"", NULL};
	size_t len = 0;
	char *buff = NULL;

	while (1)
	{
		if (getline(&buff, &len, stdin) == -1)
			break;
		buff = strtok(buff, "\t\n\r");
		args[0] = strdup(buff);
		if (check_space(buff))
		{
			status = stat_checker(args[0], av[0]);
			if (status)
			{
				if (fork() == 0)
				{
					execve(args[0], args, NULL);
				}
				else
				{
					wait(&status);
				}
			}
			else
			{
				perror("Error");
				return (0);
			}
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
