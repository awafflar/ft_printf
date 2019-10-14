#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

#include <float.h>

int     string_test(int test_count)
{
    int     ft_printf_ret = 0;
    int     printf_ret = 0;

    char    ft_printf_str[50];
    char    printf_str[50];
    char    *format[] = {
        "%s",
        "%%%s%%",
        "%%%%%s%%%%%",
        "%%%%s%%%%%%",
        "#-0.3%s#-0.3",
        "%1s",
        "%2s",
        "%3s",
        "%4s",
        "%5s",
        "%20s",
        "%21s",
        "%22s",
        "%25s",
        "%.s",
        "%.1s",
        "%.2s",
        "%.3s",
        "%.4s",
        "%.5s",
        "%.20s",
        "%.21s",
        "%.22s",
        "%.25s",
        "%1.1s",
        "%1.2s",
        "%1.3s",
        "%1.4s",
        "%1.5s",
        "%1.20s",
        "%1.21s",
        "%1.22s",
        "%1.25s",
        "%3.1s",
        "%3.2s",
        "%3.3s",
        "%3.4s",
        "%3.5s",
        "%3.20s",
        "%3.21s",
        "%3.22s",
        "%3.25s",
        "%10.1s",
        "%10.2s",
        "%10.3s",
        "%10.4s",
        "%10.5s",
        "%10.20s",
        "%10.21s",
        "%10.22s",
        "%10.25s",
        "%20.1s",
        "%20.2s",
        "%20.3s",
        "%20.4s",
        "%20.5s",
        "%20.20s",
        "%20.21s",
        "%20.22s",
        "%20.25s",
        "%25.1s",
        "%25.2s",
        "%25.3s",
        "%25.4s",
        "%25.5s",
        "%25.20s",
        "%25.21s",
        "%25.22s",
        "%25.25s",
        "%-1s",
        "%-2s",
        "%-3s",
        "%-4s",
        "%-5s",
        "%-20s",
        "%-21s",
        "%-22s",
        "%-25s",
        "%-.s",
        "%-.1s",
        "%-.2s",
        "%-.3s",
        "%-.4s",
        "%-.5s",
        "%-.20s",
        "%-.21s",
        "%-.22s",
        "%-.25s",
        "%-1.1s",
        "%-1.2s",
        "%-1.3s",
        "%-1.4s",
        "%-1.5s",
        "%-1.20s",
        "%-1.21s",
        "%-1.22s",
        "%-1.25s",
        "%-3.1s",
        "%-3.2s",
        "%-3.3s",
        "%-3.4s",
        "%-3.5s",
        "%-3.20s",
        "%-3.21s",
        "%-3.22s",
        "%-3.25s",
        "%-10.1s",
        "%-10.2s",
        "%-10.3s",
        "%-10.4s",
        "%-10.5s",
        "%-10.20s",
        "%-10.21s",
        "%-10.22s",
        "%-10.25s",
        "%-20.1s",
        "%-20.2s",
        "%-20.3s",
        "%-20.4s",
        "%-20.5s",
        "%-20.20s",
        "%-20.21s",
        "%-20.22s",
        "%-20.25s",
        "%-25.1s",
        "%-25.2s",
        "%-25.3s",
        "%-25.4s",
        "%-25.5s",
        "%-25.20s",
        "%-25.21s",
        "%-25.22s",
        "%-25.25s",
		"% s",
		"% 4s",
		"% 4.2s",
        NULL
    };

    for (int i = 0; format[i] ; i++)
    {
		test_count++;
		printf_ret = snprintf(printf_str, 50, format[i], "Ceci est un test");
		ft_printf_ret = ft_snprintf(ft_printf_str, 50, format[i], "Ceci est un test");

		if (printf_ret == -1)
			printf_ret = ft_printf_ret;

        if (printf_ret != ft_printf_ret || strcmp(printf_str, ft_printf_str))
        {
            printf("Error Test %d : printf(%s, \"%s\")\n", test_count, format[i], "Ceci est un test");
            printf("Sortie printf    : \"%s\" (%d)\n", printf_str, printf_ret);
            printf("Sortie ft_printf : \"%s\" (%d)\n", ft_printf_str, ft_printf_ret);
            return (-1);
        }
    }
    return (test_count);
}

int     hexa_test(int test_count)
{
    int     ft_printf_ret = 0;
    int     printf_ret = 0;

    char    ft_printf_str[50];
    char    printf_str[50];

    char    *format[] =
    {
        "%x",
        "%X",
        "%.6x",
        "%.6X",
        "%5x",
        "%5X",
        "%-x",
        "%-X",
        "%+x",
        "%+X",
        "%0x",
        "%0X",
        "%#x",
        "%#X",
		"% x",
		"% X",
		"% 10x",
		"% 10X",
        "%#0-3.2x",
        "%#0-3.2X",
        "%#0+- 10.2x",
        "%#0+- 10.2X",
		"%hhx",
		"%hhX",
		"%hx",
		"%hX",
		"%lx",
		"%lX",
		"%llx",
		"%llX",
		"%Lx",
		"%LX",
		"%#04x",
        NULL
    };
    int    value[] =
    {
        0,
        1,
        5,
        9,
        10,
        42,
        99,
        100,
        123456,
        987654,
        -1,
        -5,
        -9,
        -10,
        -42,
        -99,
        -100,
        -123456,
        -987654
    };

    for (int i = 0; format[i] ; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            test_count++;
			printf_ret = snprintf(printf_str, 50, format[i], value[j]);
            ft_printf_ret = ft_snprintf(ft_printf_str, 50, format[i], value[j]);

			if (printf_ret == -1)
			printf_ret = ft_printf_ret;

			if (printf_ret != ft_printf_ret || strcmp(printf_str, ft_printf_str))
            {
                printf("Error Test %d : printf(%s, %d)\n", test_count, format[i], value[j]);
                printf("Sortie printf    : \"%s\" (%d)\n", printf_str, printf_ret);
                printf("Sortie ft_printf : \"%s\" (%d)\n", ft_printf_str, ft_printf_ret);
                return (-1);
            }
        }
    }
    return (test_count);
}


int     int_test(int test_count)
{
    int     ft_printf_ret = 0;
    int     printf_ret = 0;

    char    ft_printf_str[50];
    char    printf_str[50];

    char    *format[] =
    {
        "%d",
        "%.d",
        "%3d",
        "%3.d",
        "%3.2d",
        "%-d",
        "%-.d",
        "%-3d",
        "%-3.2d",
        "%0d",
        "%0.d",
        "%03d",
        "%03.d",
        "%03.2d",
        "%0-d",
        "%0-.d",
        "%0-3d",
        "%0-3.d",
        "%0-3.2d",
        "%+d",
        "%+.d",
        "%+3d",
        "%+3.d",
        "%+3.2d",
        "%+-d",
        "%+-.d",
        "%+-3d",
        "%+-3.d",
        "%+-3.2d",
        "%+0d",
        "%+0.d",
        "%+03d",
        "%+03.d",
        "%+03.2d",
        "%+0-d",
        "%+0-3d",
        "%+0-3.d",
        "%+0-3.2d",
		"% d",
		"% 4d",
		"% 4.2d",
		"% +4.2d",
		"% 0+4.2d",
		"% 0+-4.2d",
		"% #0+-4.2d",
		"%hhd",
		"%hd",
		"%ld",
		"%lld",
		"%#d",
		"%# d",
		"%#0-3.2d",
        "%#0+- 10.2d",
       NULL
    };
    int    value[] =
    {
        0,
        1,
        5,
        9,
        10,
        42,
        99,
        100,
        123456,
        987654,
        -1,
        -5,
        -9,
        -10,
        -42,
        -99,
        -100,
        -123456,
        -987654
    };

    for (int i = 0; format[i] ; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            test_count++;
			printf_ret = snprintf(printf_str, 50, format[i], value[j]);
			ft_printf_ret = ft_snprintf(ft_printf_str, 50, format[i], value[j]);

			if (printf_ret == -1)
			printf_ret = ft_printf_ret;

			if (printf_ret != ft_printf_ret || strcmp(printf_str, ft_printf_str))
            {
                printf("Error Test %d : printf(%s, %d)\n", test_count, format[i], value[j]);
                printf("Sortie printf    : \"%s\" (%d)\n", printf_str, printf_ret);
                printf("Sortie ft_printf : \"%s\" (%d)\n", ft_printf_str, ft_printf_ret);
                return (-1);
            }
        }
    }
    return (test_count);
}

int     unsigned_test(int test_count)
{
    int     ft_printf_ret = 0;
    int     printf_ret = 0;

    char    ft_printf_str[50];
    char    printf_str[50];

    char    *format[] =
    {
        "%u",
        "%.u",
        "%3u",
        "%3.u",
        "%3.2u",
        "%-u",
        "%-.u",
        "%-3u",
        "%-3.2u",
        "%0u",
        "%0.u",
        "%03u",
        "%03.u",
        "%03.2u",
        "%0-u",
        "%0-.u",
        "%0-3u",
        "%0-3.u",
        "%0-3.2u",
        "%+u",
        "%+.u",
        "%+3u",
        "%+3.u",
        "%+3.2u",
        "%+-u",
        "%+-.u",
        "%+-3u",
        "%+-3.u",
        "%+-3.2u",
        "%+0u",
        "%+0.u",
        "%+03u",
        "%+03.u",
        "%+03.2u",
        "%+0-u",
        "%+0-3u",
        "%+0-3.u",
        "%+0-3.2u",
		"% u",
		"% 4u",
		"% 4.2u",
		"% +4.2u",
		"% 0+4.2u",
		"% 0+-4.2u",
		"% #0+-4.2u",
		"%hhu",
		"%hu",
		"%lu",
		"%llu",
 		"%#u",
		"%# u",
		"%#0-3.2u",
        "%#0+- 10.2u",
		NULL
    };
    int    value[] =
    {
        0,
        1,
        5,
        9,
        10,
        42,
        99,
        100,
        123456,
        987654,
        -1,
        -5,
        -9,
        -10,
        -42,
        -99,
        -100,
        -123456,
        -987654
    };

    for (int i = 0; format[i] ; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            test_count++;
			printf_ret = snprintf(printf_str, 50, format[i], value[j]);
			ft_printf_ret = ft_snprintf(ft_printf_str, 50, format[i], value[j]);

			if (printf_ret == -1)
			printf_ret = ft_printf_ret;

			if (printf_ret != ft_printf_ret || strcmp(printf_str, ft_printf_str))
            {
                printf("Error Test %d : printf(%s, %d)\n", test_count, format[i], value[j]);
                printf("Sortie printf    : \"%s\" (%d)\n", printf_str, printf_ret);
                printf("Sortie ft_printf : \"%s\" (%d)\n", ft_printf_str, ft_printf_ret);
                return (-1);
            }
        }
    }
    return (test_count);
}

int     octal_test(int test_count)
{
    int     ft_printf_ret = 0;
    int     printf_ret = 0;

    char    ft_printf_str[50];
    char    printf_str[50];

    char    *format[] =
    {
        "%o",
        "%.o",
        "%3o",
        "%3.o",
        "%3.2o",
        "%-o",
        "%-.o",
        "%-3o",
        "%-3.2o",
        "%0o",
        "%0.o",
        "%03o",
        "%03.o",
        "%03.2o",
        "%0-o",
        "%0-.o",
        "%0-3o",
        "%0-3.o",
        "%0-3.2o",
        "%+o",
        "%+.o",
        "%+3o",
        "%+3.o",
        "%+3.2o",
        "%+-o",
        "%+-.o",
        "%+-3o",
        "%+-3.o",
        "%+-3.2o",
        "%+0o",
        "%+0.o",
        "%+03o",
        "%+03.o",
        "%+03.2o",
        "%+0-o",
        "%+0-3o",
        "%+0-3.o",
        "%+0-3.2o",
		"% o",
		"% 4o",
		"% 4.2o",
		"% +4.2o",
		"% 0+4.2o",
		"% 0+-4.2o",
		"% #0+-4.2o",
		"%hho",
		"%ho",
		"%lo",
		"%llo",
		"%#o",
		"%# o",
		"%#0-3.2o",
        "%#0+- 10.2o",
		NULL
    };
    int    value[] =
    {
        0,
        1,
        5,
        9,
        10,
        42,
        99,
        100,
        123456,
        987654,
        -1,
        -5,
        -9,
        -10,
        -42,
        -99,
        -100,
        -123456,
        -987654
    };

    for (int i = 0; format[i] ; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            test_count++;
			printf_ret = snprintf(printf_str, 50, format[i], value[j]);
			ft_printf_ret = ft_snprintf(ft_printf_str, 50, format[i], value[j]);
        
			if (printf_ret == -1)
				printf_ret = ft_printf_ret;

		
			if (printf_ret != ft_printf_ret || strcmp(printf_str, ft_printf_str))
            {
                printf("Error Test %d : printf(%s, %d)\n", test_count, format[i], value[j]);
                printf("Sortie printf    : \"%s\" (%d)\n", printf_str, printf_ret);
                printf("Sortie ft_printf : \"%s\" (%d)\n", ft_printf_str, ft_printf_ret);
                return (-1);
            }
        }
    }
    return (test_count);
}

int     char_test(int test_count)
{
    int     ft_printf_ret = 0;
    int     printf_ret = 0;

    char    ft_printf_str[50];
    char    printf_str[50];
    char    *format[] = {
        "%c",
        "%4c",
        "%25c",
        "%.c",
        "%.1c",
        "%.2c",
        "%.25c",
        "%1.1c",
        "%1.4c",
        "%3.1c",
        "%3.4c",
        "%-4c",
        "%-.c",
        "%-.1c",
        "%-.4c",
        "%-1.1c",
        "%-1.4c",
        "%-3.1c",
        "%-3.4c",
        "%-10.1c",
        "%-10.4c",
		"% c",
		"% 4c",
		"% 4.2c",
        NULL
    };
	int		value[]=
	{
		0,
		10,
		32,
		43,
		48,
		57,
		65,
		90,
		92,
		97,
		122,
		126,
};

    for (int i = 0; format[i] ; i++)
    {
	    for (int j = 0; j < 12; j++)
        {
            test_count++;
			printf_ret = snprintf(printf_str, 50, format[i], value[j]);
			ft_printf_ret = ft_snprintf(ft_printf_str, 50, format[i], value[j]);
        
			if (printf_ret == -1)
				printf_ret = ft_printf_ret;

		
			if (printf_ret != ft_printf_ret || strcmp(printf_str, ft_printf_str))
            {
                printf("Error Test %d : printf(%s, %d)\n", test_count, format[i], value[j]);
                printf("Sortie printf    : \"%s\" (%d)\n", printf_str, printf_ret);
                printf("Sortie ft_printf : \"%s\" (%d)\n", ft_printf_str, ft_printf_ret);
                return (-1);
            }
        }
    }
    return (test_count);
}

int     pointer_test(int test_count)
{
    int     ft_printf_ret = 0;
    int     printf_ret = 0;

    char    ft_printf_str[50];
    char    printf_str[50];

    char    *format[] =
    {
        "%p",
        "%.p",
        "%3p",
        "%3.p",
        "%3.2p",
        "%-p",
        "%-.p",
        "%-3p",
        "%-3.2p",
        "%0p",
        "%0.p",
        "%03p",
        "%03.p",
        "%03.2p",
        "%0-p",
        "%0-.p",
        "%0-3p",
        "%0-3.p",
        "%0-3.2p",
        "%+p",
        "%+.p",
        "%+3p",
        "%+3.p",
        "%+3.2p",
        "%+-p",
        "%+-.p",
        "%+-3p",
        "%+-3.p",
        "%+-3.2p",
        "%+0p",
        "%+0.p",
        "%+03p",
        "%+03.p",
        "%+03.2p",
        "%+0-p",
        "%+0-3p",
        "%+0-3.p",
        "%+0-3.2p",
		"% p",
		"% 4p",
		"% 4.2p",
		"% +4.2p",
		"% 0+4.2p",
		"% 0+-4.2p",
		"% #0+-4.2p",
		"%hhp",
		"%hp",
		"%lp",
		"%llp",
		"%#p",
		"%# p",
		"%#0-3.2p",
        "%#0+- 10.2p",
		NULL
    };
    int    value[] =
    {
        0,
        1,
        5,
        9,
        10,
        42,
        99,
        100,
        123456,
        987654,
        -1,
        -5,
        -9,
        -10,
        -42,
        -99,
        -100,
        -123456,
        -987654,
    };

    for (int i = 0; format[i] ; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            test_count++;
			printf_ret = snprintf(printf_str, 50, format[i], &value[j]);
			ft_printf_ret = ft_snprintf(ft_printf_str, 50, format[i], &value[j]);

			if (printf_ret == -1)
			printf_ret = ft_printf_ret;

			if (printf_ret != ft_printf_ret || strcmp(printf_str, ft_printf_str))
            {
                printf("Error Test %d : printf(%s, %p)\n", test_count, format[i], &value[j]);
                printf("Sortie printf    : \"%s\" (%d)\n", printf_str, printf_ret);
                printf("Sortie ft_printf : \"%s\" (%d)\n", ft_printf_str, ft_printf_ret);
                return (-1);
            }
        }
    }
    return (test_count);
}

int     float_test(int test_count)
{
    int     ft_printf_ret = 0;
    int     printf_ret = 0;

    char    ft_printf_str[50];
    char    printf_str[50];

    char    *format[] =
    {
        "%f",
        "%.f",
        "%3f",
        "%3.f",
        "%3.2f",
        "%-f",
        "%-.f",
        "%-3f",
        "%-3.2f",
        "%0f",
        "%0.f",
        "%03f",
        "%03.f",
        "%03.2f",
        "%0-f",
        "%0-.f",
        "%0-3f",
        "%0-3.f",
        "%0-3.2f",
        "%+f",
        "%+.f",
        "%+3f",
        "%+3.f",
        "%+3.2f",
        "%+-f",
        "%+-.f",
        "%+-3f",
        "%+-3.f",
        "%+-3.2f",
        "%+0f",
        "%+0.f",
        "%+03f",
        "%+03.f",
        "%+03.2f",
        "%+0-f",
        "%+0-3f",
        "%+0-3.f",
        "%+0-3.2f",
		"% f",
		"% 4f",
		"% 4.2f",
		"% +4.2f",
		"% 0+4.2f",
		"% 0+-4.2f",
		"% #0+-4.2f",
		"%#f",
		"%# f",
		"%#0-3.2f",
        "%#0+- 10.2f",
		"%.100f",
       NULL
    };
    double    value[] =
    {
        0.0,
        1.0,
        5.0,
        9.99,
		10.59,
		10.55,
        10.5,
        42.42424242424242424242424242,
        99.0,
        100.0,
        90.0,
        -1.0,
        -5.0,
        -9.99,
        -10.5,
        -42.42424242424242424242424242,
        -99.0,
        -100.0,
		-987654.0,
		-87654.0,
        };

    for (int i = 0; format[i] ; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            test_count++;
			printf_ret = snprintf(printf_str, 50, format[i], value[j]);
			ft_printf_ret = ft_snprintf(ft_printf_str, 50, format[i], value[j]);

			if (printf_ret == -1)
			printf_ret = ft_printf_ret;

			if (printf_ret != ft_printf_ret || strcmp(printf_str, ft_printf_str))
            {
                printf("Error Test %d : printf(%s, %f)\n", test_count, format[i], value[j]);
                printf("Sortie printf    : \"%s\" (%d)\n", printf_str, printf_ret);
                printf("Sortie ft_printf : \"%s\" (%d)\n", ft_printf_str, ft_printf_ret);
                return (-1);
            }
        }
    }
    return (test_count);
}

int main()
{
    int     test_count = 0;

    test_count = string_test(test_count);
    if (test_count == -1)
        return (-1);
	printf("String tests OK\n");
    test_count = int_test(test_count);
    if (test_count == -1)
        return (-1);
	printf("Int tests OK\n");
	test_count = hexa_test(test_count);
	if (test_count == -1)
		return (-1);
	printf("Hexa tests OK\n");
	test_count = unsigned_test(test_count);
	if (test_count == -1)
		return (-1);
	printf("Unsigned tests OK\n");
	test_count = octal_test(test_count);
	if (test_count == -1)
		return (-1);
	printf("Octal tests OK\n");
	test_count = char_test(test_count);
	if (test_count == -1)
		return (-1);
	printf("Char tests OK\n");
	test_count = pointer_test(test_count);
	if (test_count == -1)
		return (-1);
	printf("Pointer tests OK\n");
	test_count = float_test(test_count);
	if (test_count == -1)
		return (-1);
	printf("Floats tests OK\n");
	printf("%d TESTS SUCCESSFUL\n", test_count);
	
	printf("================\tHANDTESTS\t================\n");
	printf("%f %lf %Lf\n", 1.42, 1.42, 1.42l);
	ft_printf("%f %lf %Lf\n", 1.42, 1.42, 1.42l);
	return (0);
}
