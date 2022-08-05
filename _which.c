#include "main.h"
/**
 * _which - takes an argument and checks if the path exists
 * @av: argument
 * Return: the full path or NULL if it doesn't exists
 */

char *_which(char *av)
{
	char *path = NULL, *pathdup = NULL, *full_path = NULL, *token = NULL;
	struct stat st;

	if (!av)
		return (NULL);
	path = _getenv("PATH"); /* get the PATH enviroment variable */
	pathdup = _strdup(path);
	token = strtok(pathdup, ":"); /* tokenize the PATH */
	while (token)
	{
		full_path = malloc(sizeof(char) * (strlen(token) + strlen(av) + 2));
		_strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, av);
		if (stat(full_path, &st) == 0) /* token + '/' + argument is a path? */
		{
			free(pathdup);
			return (full_path); /* return full_path */
		}
		free(full_path);
		full_path = NULL;
		token = strtok(NULL, ":"); /* move on to the next token */
	}
	free(full_path);
	free(pathdup);
	return (NULL);
}
