#include "main.h"

char *_getenv(const char *name, char **env)
{
	int *buff;
	int i, j;
	int status;

	for(i = 0; env[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; env[i][j] != "="; j++)
		{
			if (name[j] != env[i][j])
			{
				status = 0;
				break;
			}
		}

	}
	return (NULL);
}
