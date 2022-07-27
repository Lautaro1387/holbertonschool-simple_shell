#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	int i = 0, a = 0;

	while(env[a])
	{
	while(environ[i])
	{
		printf("%s\n", environ[i++]);
		printf("%s\n", env[a++]);
	}
	}
	return (0);
}
