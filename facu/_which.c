#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	char *path, *pathdup, *file;
	struct stat st;

	if (argc < 2)
		return (1);
	path = getenv("PATH");
	pathdup = strdup(path);
	pathdup = strtok(pathdup, ":");
	while (pathdup)
	{
		while (pathdup && pathdup[0] == '/')
			pathdup++;
		file = strtok(pathdup, "/");
		while (file)
		{
			if (stat(file, &st) == 0)
			{
				printf("%s\n", pathdup);
				return (0);
			}
			file = strtok(NULL, "/");
		}
		pathdup = strtok(NULL, ":");
	}
	return (-1);
}
