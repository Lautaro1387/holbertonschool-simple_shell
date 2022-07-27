#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	char *path, *pathdup, *full_path;
	struct stat st;

	if (argc < 2)
		return (1);
	path = getenv("PATH");
	pathdup = strdup(path);
	pathdup = strtok(pathdup, ":");
	while (pathdup)
	{
		full_path = strdup(pathdup);
		strcat(full_path, "/");
		strcat(full_path, argv[1]);
		if (stat(full_path, &st) == 0)
		{
			printf("%s\n", full_path);
			break;
		}
		pathdup = strtok(NULL, ":");
	}
	return (-1);
}
