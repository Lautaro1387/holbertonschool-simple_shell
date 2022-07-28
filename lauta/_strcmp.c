#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * _strcmp - Function that compares two strings.
 * @s1: First element.
 * @s2: Second element.
 * Return: s1.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
		return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
