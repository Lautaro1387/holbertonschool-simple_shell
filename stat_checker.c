#include "main.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int stat_checker(char *ac, char *av)
{
	struct stat st;
	
	(void) ac;
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
