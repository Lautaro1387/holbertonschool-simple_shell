#include "main.h"
/**
*
*
*
*
*/

int main(__attribute__((unused)) int ac,  __attribute__((unused)) char **av, char **env)
{
	char *buff = NULL;
	int status = 0;
	int child;
	char *args[1024];
	size_t str, len = 0;
	char *token;

	while (1)
	{
		if (getline(&buff, &len, stdin) == -1)
			break;
		token = strtok(buff, "\t\n\r");
		for (str = 0; str < 1024 && token != NULL; str++)
		{
			args[str] = token;
			token = strtok(NULL, "\t\n\r");
		}
		args[str] = NULL;
		child = fork();
		if (!args[0])
		{
			free(args[0]);
			free(buff);
			return (0);
		}
		if (child == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				perror("");
				return (0);
			}
		}
		else
			wait(&status);
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
/**
 *
 *
 *
 */
void token_checker(char *buff, char **array, char *delim)
{
	int i = 0;

	array[i] = strtok(buff, delim);
	while (array[i])
	{
		i++;
		array[i] = strtok(NULL, delim);
	}
}
