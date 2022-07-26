#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	int count = 0;

	while (av[count])
		count++;
	printf("%d", (count - 1));
	return (0);
}
