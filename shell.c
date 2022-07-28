#include "main.h"
extern char **environ;
/**
*
*
*
*
*/

int main(void)
{
	char *args[] = {"", NULL};
	char *buffer = NULL;
	size_t len = 0;

	printf("#cisfun$ ");
	getline(&buffer, &len, stdin);
	buffer = strtok(buffer, "\n");
	args[0] = buffer;
	if (execve(args[0], args, NULL) == -1)
	{
		perror("Error:");
		return (1);
	}
	return (0);
}
