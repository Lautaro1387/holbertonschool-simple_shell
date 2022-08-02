#include "main.h"

char *_which(char *av)
{
	char *path, *pathdup, *full_path;
	struct stat st;

	if (!av)
		return (NULL);
	path = getenv("PATH");
	pathdup = strdup(path);
	pathdup = strtok(pathdup, ":");
	while (pathdup)
	{
		full_path = strdup(pathdup);
		strcat(full_path, "/");
		strcat(full_path, av);
		if (stat(full_path, &st) == 0)
		{
			printf("%s\n", full_path);
			break;
		}
		pathdup = strtok(NULL, ":");
	}
	return (full_path);
}
