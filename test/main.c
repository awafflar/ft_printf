#include <stdio.h>
#include "ft_printf.h"

int main()
{

	int		real;
	int		mine;

	printf("\t###############\tMODULO\t###############\n");

	printf("### MODULO\n");
	real = printf("%%\n");
	mine = ft_printf("%%\n");
	printf("Caracteres ecrits: printf:%d ft_printf:%d\n\n", real, mine);

	printf("\t###############\t%%s\t###############\n");

	printf("### CHAINE VIDE\n");
	real = printf("%s\n", "");
	mine = ft_printf("%s\n", "");
	printf("Caracteres ecrits: printf:%d ft_printf:%d\n\n", real, mine);
	
	printf("### CHAINE SIMPLE\n");
	real = printf("%s\n", "Ceci est un test");
	mine = ft_printf("%s\n", "Ceci est un test");
	printf("Caracteres ecrits: printf:%d ft_printf:%d\n\n", real, mine);

	printf("### CHAINE %%3.2\n");
	real = printf("%3.2s\n", "Ceci est un test");
	mine = ft_printf("%3.2s\n", "Ceci est un test");
	printf("Caracteres ecrits: printf:%d ft_printf:%d\n\n", real, mine);

	printf("### CHAINE %%-3.2 + CHAINE\n");
	real = printf("%-3.2s%s\n", "Ceci est un test", "test2");
	mine = ft_printf("%-3.2s%s\n", "Ceci est un test", "test2");
	printf("Caracteres ecrits: printf:%d ft_printf:%d\n\n", real, mine);

	printf("\t###############\t%%d\t###############\n");

	printf("### 42\n");
	real = printf("%d\n", 42);
	mine = ft_printf("%d\n", 42);
	printf("Caracteres ecrits: printf:%d ft_printf:%d\n\n", real, mine);

	printf("### %%6.4d 12\n");
	real = printf("%6.4d\n", 12);
	mine = ft_printf("%6.4d\n", 12);
	printf("Caracteres ecrits: printf:%d ft_printf:%d\n\n", real, mine);
}
