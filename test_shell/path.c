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
	list_t *prev, *new, *head, *temp;
	
	path = getenv("PATH");
	pathdup = strdup(path);
	pathdup = strtok(pathdup, ":");
	
	/* create first node */
    head = malloc(sizeof(list_t));
	prev = head;

	while (pathdup)
	{
		if (!prev->str)
			new = prev;
		else
		{
			/* create new node */
			new = malloc(sizeof(list_t));
			if (!new)
				return (0);
			prev->next = new;
			prev = new;
		}
		new->str = strdup(pathdup);
		new->len = strlen(pathdup);
		new->next = NULL;
		/* next token */
		pathdup = strtok(NULL, ":");
	}


	temp = head;
	while (temp && temp->str)
	{
		printf("%s\n", temp->str);
		temp = temp->next;
	}

	return (0);
}
