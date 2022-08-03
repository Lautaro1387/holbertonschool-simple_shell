#include "main.h"
/**
*
*
*/
int main(__attribute__((unused)) int ac,  __attribute__((unused)) char **av, char **env)
{
	char *buff = NULL, *token, *args[1024];
	int status = 0, i = 0, interactive = 1;
	size_t str = 0, len = 0;

	while (interactive)
	{
		interactive = isatty(0);
		if (getline(&buff, &len, stdin) == -1)
			break;
		token = strtok(buff, " \t\n\r");
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
		if (!_strcmp(token, "exit"))
                {
                        free(buff);
                        return (str);
                }
                if (_strcmp(buff, "env") == 0)
                {
                	for (; env[i] != NULL; i++)
                        	printf("%s\n", env[i]);
                        continue;
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
