#include "main.h"
/**
 * _getenv - get an environment variable
 * @name: name of the variable
 * Return: the environment variable or NULL
 */
char *_getenv(const char *name)
{
	int i, j;
	int status;

	for (i = 0; environ[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}
		if (status)
		{
			return (&environ[i][j + 1]);
		}
	}
	return (NULL);
}
