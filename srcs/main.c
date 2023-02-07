#include <stdlib.h>
#include <stdio.h>
#include "calc_plus.h"

static int __usage_error(char *filename)
{
	fprintf(stderr, "%s\n", "Usage Error");
	fprintf(stderr, "Usage: %s <expression>\n", filename);
	return (EXIT_FAILURE);
}

int main (int ac, char *av[])
{
	if (ac != 2)
		return (__usage_error(av[0]));
	if (!calc_plus(av[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
