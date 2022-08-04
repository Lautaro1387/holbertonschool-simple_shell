#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * _strcpy - Function.
 * @dest: Argument.
 * @src: Argument.
 * Return: dest.
 */
char *_strcpy(char *dest, char *src)
{
	int fin;

	for (fin = 0; src[fin] != 0; fin++)
	{
		dest[fin] = src[fin];
	}
	dest[fin] = '\0';
	return (dest);
}
