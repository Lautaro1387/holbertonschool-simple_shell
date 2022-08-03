#include "main.h"

char *_which(char *av)
{
	char *path = NULL, *pathdup = NULL, *full_path = NULL;
	struct stat st;

	if (!av)
		return (NULL);
	path = getenv("PATH");
	pathdup = _strdup(path);
	pathdup = strtok(pathdup, ":");
	while (pathdup)
	{
		full_path = _strdup(pathdup);
		strcat(full_path, "/");
		strcat(full_path, av);
		if (stat(full_path, &st) == 0)
		{
			return (full_path);
		}
		else
		{
			free(full_path);
			pathdup = strtok(NULL, ":");
		}
	}
	free(full_path);
	free(pathdup);
	return (NULL);
}
