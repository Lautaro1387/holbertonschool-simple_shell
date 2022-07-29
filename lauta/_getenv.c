#include "main.h"

char *_getenv(const char *name, char **env)
{
	int i = 0;
	char *buff;

	buff = strtok(buff, "=");
	buff = strdup(buff);
	while(env[i])
	{
		i++;
	}
	return (0);
}
