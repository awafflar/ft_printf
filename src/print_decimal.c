#include "ft_printf_core.h"

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

	(void)fmt;
	(void)args;
	n = get_arg_ll(args->ap, args->current);
	buff_addstr(buff, ft_lltostr(n, str));
}
