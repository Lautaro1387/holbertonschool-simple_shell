#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - fork & wait example
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i;

	my_pid = getpid();
	child_pid = fork();
	for (i = 0; i < 5; i++)
	{
		if (child_pid == -1)
		{
			perror("Error:");
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Erorr:");
			}
			printf("%u\n", child_pid);
		}
		else
		{
			wait(&status);
			printf("%u\n", my_pid);
		}
	}
	return (0);
}
