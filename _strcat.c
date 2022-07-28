#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * _strcat - Function that concatenates two strings.
 * @dest: element.
 * @src: element.
 * Return: return dest.
 */
char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != 0; a++)
	{
	}
	for (b = 0; src[b] != 0; b++)
	{
		dest[a] = src[b];
		a++;
	}
	src[b] = '\0';
	return (dest);
}
