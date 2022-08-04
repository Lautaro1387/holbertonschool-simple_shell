#include "main.h"

char *_which(char *av)
{
	char *path = NULL, *pathdup = NULL, *full_path = NULL, *token = NULL;
	struct stat st;

	if (!av)
		return (NULL);
	path = getenv("PATH");
	pathdup = strdup(path);
	token = strtok(pathdup, ":");
	while (token)
	{
		full_path = malloc(sizeof(char) * (strlen(token) + strlen(av) + 2));
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, av);
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
