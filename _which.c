#include "main.h"

char *_which(char *av)
{
	char *path = NULL, *pathdup = NULL, *full_path = NULL, *token = NULL;
	struct stat st;

	if (!av)
		return (NULL);
	path = _getenv("PATH");
	pathdup = _strdup(path);
	token = strtok(pathdup, ":");
	while (token)
	{
		full_path = malloc(sizeof(char) * (_strlen(token) + _strlen(av) + 2));
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, av);
		if (stat(full_path, &st) == 0)
		{
			free(pathdup);
			return (full_path);
		}
		free(full_path);
		full_path = NULL;
		token = strtok(NULL, ":");
	}
	free(full_path);
	free(pathdup);
	return (NULL);
}
