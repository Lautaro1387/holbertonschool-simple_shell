#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *args[] = {"", NULL};
	char *buff = NULL;
	size_t len = 0;
	
	printf("#cisfun$ ");
	getline(&buff, &len, stdin);
	buff = strtok(buff, "\n");
	args[0] = buff;
	if (execve(args[0], args, NULL) == -1)
	{
		perror("Error:");
		return (1);
	}
	return (0);
}
