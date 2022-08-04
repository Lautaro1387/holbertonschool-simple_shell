#include "main.h"

/**
* _strlen - entry point
* @s: variable
* Return: the length
*/

int _strlen(char *s)
{
	char i;
	int lenght = 0;

	if (*(s) != 00)
	while (i != '\0')
	{
		lenght++;
		i = *(s + lenght);
	}
	return (lenght);
}
