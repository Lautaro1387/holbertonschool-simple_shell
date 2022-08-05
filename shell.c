#include "main.h"
/**
* main - Function.
* @ac: Unused.
* @av: Unused.
* @env: Environment variables.
* Return: 0.
*/
int main(int ac, char **av, char **env)
{
	char *buff = NULL, *token, *strerr, *args[1024];
	size_t str = 0, len = 0;
	int not_found = 0;

	(void) ac, (void) av;
	while (1)
	{
		if (isatty(0) == 1)
			write(1, "#cisfun$ ", 9);
		if (getline(&buff, &len, stdin) == -1)
			break; /* if the user press ctrl+d exits */
		token = strtok(buff, " \t\n"); /* tokenize the getline */
		if (!token)
			break;
		if (_specstr(token, env) == 0) /* special string "env" behavior */
			continue;
		if (_specstr(token, env) == 1) /* special string "exit" behavior */
		{
			free(buff);
			return (str); /* return the number of arguments before exit */
		}
		for (str = 0; str < 1024 && token != NULL; str++)
		{
			args[str] = token; /* now. tokens are strings with a numerical position */
			token = strtok(NULL, " \t\n");
		}
		args[str] = NULL; /* last string is NULL */
		if (!args[0]) /* if the first string is NULL we freee and return */
		{
			free(args[0]);
			free(buff);
			return (0);
		}
		if (pathverify(args[0]) == 1) /* first string is a path? */
		{
			strerr = args[0]; /* save the first string in case which returns NULL */
			args[0] = _which(args[0]);
			if (!args[0]) /* if which returns NULL, we return an error message */
			{
				write(2, "./hsh: 1: ", 10);
				write(2, strerr, strlen(strerr));
				write(2, ": not found\n", 12);
				not_found = 127;
				continue;
			}
			created_fork(args, env); /* create a child process with the full path */
			free(args[0]); /* we free after used it */
		}
		else
			created_fork(args, env); /* create a child process with the user path */
	}
	free(buff);
	return (not_found);
}
/**
 * _specstr - Special strings.
 * @token: String.
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

	if (fork() == 0) /* creats a child process */
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("Error:");
			return (0);
		}
	}
	else
		wait(&status); /* waits for the son process */
	return (0);
}
/**
 * pathverify - takes an argument and check if it is a path
 * @args: arguments
 * Return: 1 on success or 0 if it fails
 */
int pathverify(char *args)
{
	int i = 0;

	while (args[i] != '/' && args[i])
		i++;
	if (args[i] != '/')
		return (1);
	return (0);
}
