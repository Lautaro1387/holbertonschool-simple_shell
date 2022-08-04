#include "main.h"
/**
* main - Function.
* @ac: Unused.
* @av: Unused.
* @env: Environment variables.
* Return: 0.
*/
int main(int ac, __attribute__((unused)) char **av, char **env)
{
	char *buff = NULL, *token, *strerr, *args[1024];
	size_t str = 0, len = 0;
	int not_found = 0;

	(void)ac;
	while (1)
	{
		if (getline(&buff, &len, stdin) == -1)
			break;
		token = strtok(buff, " \t\n\r");
		if (!token)
			break;
		if (_specstr(token, env) == 0)
			continue;
		if (_specstr(token, env) == 1)
		{
			free(buff);
			return (str);
		}
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
		if (pathverify(args[0]) == 1)
		{
			strerr = args[0];
			args[0] = _which(args[0]);
			if (!args[0])
			{
				write(2, "./hsh: 1: ", 10);
				write(2, strerr, _strlen(strerr));
				write(2, ": not found\n", 12);
				not_found = 127;
				continue;
			}
			created_fork(args, env);
			free(args[0]);
		}
		else
			created_fork(args, env);
	}
	free(buff);
	return (not_found);
}
/**
 * _specstr - Special strings.
 *not found @token: String.
 * @str: Number of argument.
 * @envi: Environment variables.
 * Return: .
 */
int _specstr(char *token, char **envi)
{
	int i;

	if (_strcmp(token, "exit") == 0)
	{
		return (1);
	}
	if (_strcmp(token, "env") == 0)
	{
		for (i = 0; envi[i]; i++)
			printf("%s\n", envi[i]);
		return (0);
	}
		return (-1);
}
/**
 * created_fork - Create new proccess.
 * @args: Strings.
 * @env: Environment variables.
 * Return: 0.
 */
int created_fork(char **args, char **env)
{
	int status = 0;

	if (fork() == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("Error:");
			return (0);
		}
	}
	else
		wait(&status);
	return (0);
}
int pathverify(char *args)
{
	int i = 0;

	while (args[i] != '/' && args[i])
		i++;
	if (args[i] != '/')
		return (1);
	return (0);
}
