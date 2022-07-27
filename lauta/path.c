#include "main.h"
int main(int ac, char **av)
{
	char *buff, *path;

	path = getenv("PATH");
	buff = strdup(path);
	buff = strtok(buff, ":");
	printf ("%s\n", buff);
	while(buff)
	{
		printf("%s\n", buff);
		buff = strtok(NULL, ":");
	}
	return (0);
}
