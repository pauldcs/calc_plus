#include <stdlib.h>
#include "libstringf.h"
#include "calc_plus.h"

static int __usage_error(char *filename)
{
	fputstr(2, "%rs\n", "Usage Error");
	fputstr(2, "Usage: %s <expression>\n", filename);
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