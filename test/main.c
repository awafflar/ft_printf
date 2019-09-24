#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

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
        NULL
    };

    for (int i = 0; format[i] ; i++)
    {
        test_count++;
        printf_ret = snprintf(printf_str, 50, format[i], "Ceci est un test");
        ft_printf_ret = ft_snprintf(ft_printf_str, 50, format[i], "Ceci est un test");

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
        "%0-.d"
        "%0-3d",
        "%0-3.d",
        "%0-3.2d",
        "%+d",
        "%+.d"
        "%+3d",
        "%+3.d",
        "%+3.2d",
        "%+-d",
        "%+-.d"
        "%+-3d",
        "%+-3.d",
        "%+-3.2d",
        "%+0d",
        "%+0.d"
        "%+03d",
        "%+03.d",
        "%+03.2d",
        "%+0-d",
        "%+0-3d",
        "%+0-3.d",
        "%+0-3.2d",
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

int main()
{
    int     test_count = 0;

    test_count = string_test(test_count);
    if (test_count == -1)
        return (-1);
    test_count = int_test(test_count);
    if (test_count == -1)
        return (-1);

	return (0);
}
