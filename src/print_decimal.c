#include "ft_printf_core.h"

#include <stdio.h>

static long long	get_arg_ll(va_list ap, int n)
{	
	long long	ret;
	va_list		list;

	va_copy(list, ap);
	while (n--)
		ret = va_arg(list, long long);
	va_end(list);
	return (ret);
}

void			print_decimal(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	long long	n;
	char		*str;
	size_t		size;
	size_t		zero;

	n = get_arg_ll(args->ap, args->current);
	str = ft_lltostr(n);
	size = ft_strlen(str);
	if (fmt->precision != -1 && fmt->precision > size)
		zero = fmt->precision - size;
	buff_addnchar(buff, '0', zero);
	buff_addnstr(buff, str, size);
}
