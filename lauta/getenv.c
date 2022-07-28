#include "main.h"

char *_getenv(const char *name, char **env)
{
	int i = 0;
	char *dup;

	while (env[i] && _strcmp(name, dup))
	{
		printf("%s\n", env[i++]);
	}
	if (env[i])
	{

	}
	return (0);
}
