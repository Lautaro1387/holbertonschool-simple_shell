#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
int main(void)
{
	char *path, *pathdup;
	typedef struct list_s
	{
		char *str;
		unsigned int len;
		struct list_s *next;
	} list_t;
	list_t *new, *temp;
	
	path = getenv("PATH");
	pathdup = strdup(path);
	pathdup = strtok(pathdup, ":");
	new = malloc(sizeof(list_t));
	if (!new)
		return (0);
	new->str = strdup(pathdup);
	new->len = strlen(new->str);
	new->next = NULL;
	while (pathdup)
	{
		new = malloc(sizeof(list_t));
		if (!new)
			return (0);
		pathdup = strtok(NULL, ":");
		new->str = strdup(pathdup);
		temp = new;
		while (temp != NULL)
		{
		printf("%s\n", new->str);
		temp = temp->next;
		}
	}
	return (0);
}
