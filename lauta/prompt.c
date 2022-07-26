#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *buff = NULL;
	size_t len;
	char *path;
	char *pathdup;

    printf("$ ");
    getline(&buff, &len, stdin);
    printf("%s", buff);
	path = getenv("PATH");
	pathdup = strdup(path);
	pathdup = strtok(pathdup, ":");
	while (pathdup)
	{
		printf("%s\n", pathdup);
		pathdup = strtok(NULL, ":");
	}
    return (0);
}
