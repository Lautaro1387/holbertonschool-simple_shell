#include "main.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int _stat(char *ac, char *av)
{
	(void) ac;
	struct stat st;

		if (stat(av, &st) == 0)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	return (0);
}
