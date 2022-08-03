#include "main.h"
/**
*
*
*/
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
	char *buff = NULL, *token, *args[1024];
	int status = 0;
	size_t str = 0, len = 0;

	while (1)
	{
		if (getline(&buff, &len, stdin) == -1)
			break;
		token = strtok(buff, " \t\n\r");
		if (!token)
			break;
		if (_specstr(token, str, env) >= 0)
		{
			free(buff);
			return (str);
		}
		else if (_specstr(token, str, env) == -1)
			continue;
		for (str = 0; str < 1024 && token != NULL; str++)
		{
			args[str] = token;
			token = strtok(NULL, " \t\n\r");
		}
		args[str] = NULL;
		if (!args[0])
		{
			free(args[0]);
			free(buff);
			return (0);
		}
		if (fork() == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				perror("Error");
				return (0);
			}
		}
		else
			wait(&status);
	}
	free(buff);
	return (0);
}
int _specstr(char *token, int str, char **env)
{
	int i = 0;

	if (_strcmp(token, "exit") == 0)
	{
		return (str);
	}
	else if (_strcmp(token, "env") == 0)
	{
		for (; env[i] != NULL; i++)
			printf("%s\n", env[i]);
		return (-1);
	}
	else
		return (-2);
}
