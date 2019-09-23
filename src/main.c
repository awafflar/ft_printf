#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("%%\n");
	ft_printf("%%\n");
	printf("\n");

	printf("%s\n", "");
	ft_printf("%s\n", "");
	printf("\n");
	
	printf("%s\n", "Ceci est un test");
	ft_printf("%s\n", "Ceci est un test");
	printf("\n");

	printf("%3.2s\n", "Ceci est un test");
	ft_printf("%3.2s\n", "Ceci est un test");
	printf("\n");

	printf("%-3.2s%s\n", "Ceci est un test", "test2");
	ft_printf("%-3.2s%s\n", "Ceci est un test", "test2");
	printf("\n");

	printf("%d\n", 42);
	ft_printf("%d\n", 42);
	printf("\n");
}
