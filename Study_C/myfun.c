#include <stdio.h>

int dump(const char *p, int array_size)
{
	for (int i = 0; i < array_size - 1; i++)
		printf("%p %s %p %c - %d\n", p, p, p + i, *(p + i), *(p + i));

	return 0;
}
