#include "main.h"
/**
*
*
*/
int main(__attribute__((unused)) int ac,  __attribute__((unused)) char **av, char **env)
{
	char *buff = NULL, *token, *args[1024];
	int status = 0;
	size_t str, len = 0;

	while (1)
	{
		if (isatty(0))
			printf("# ");
		if (getline(&buff, &len, stdin) == -1)
			break;
		token = strtok(buff, " \t\n");
		if (_strcmp(token, "exit") == 0)
		{
			free(buff);
			return (2);
		}
		if (_strcmp(token, "env") == 0)
		{
			free(buff);
			return (2);
		}
		for (str = 0; str < 1024 && token != NULL; str++)
		{
			args[str] = token;
			token = strtok(NULL, " \t\n");
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
