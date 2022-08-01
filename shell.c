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

	(void) av;
	while (1)
	{
		if (getline(&buff, &len, stdin) == -1)
			break;
		buff = strtok(buff, "\t\n");
		args[0] = check_space(strdup(buff));
		if (!args[0])
			return (0);
		if (fork() == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
				return (0);
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
char *check_space(char *buff)
{
	int i = 0, non_space = 0;

	while (buff[i])
	{
		if (buff[i] != ' ' && buff[i])
		{
			buff[non_space] = buff[i];
			non_space++;
		}
		i++;
	}
	buff[non_space] = '\0';
	return (buff);
}
/**
 * main - stat example
 *
 * Return: 1 if it is true or 0 if it is false.
 */
int stat_checker(char *args)
{
    struct stat st;

	if (stat(args, (&st)) == 0)
	{
        	return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}
