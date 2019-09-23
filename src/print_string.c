#include "ft_printf_core.h"

static char		*get_arg_str(va_list ap, int n)
{	
	char	*ret;
	va_list	list;

	va_copy(list, ap);
	while (n--)
		ret = va_arg(list, char*);
	va_end(list);
	return (ret);
}

void		print_str(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	char	*str;
	size_t	size;
	size_t	padding;

	str = get_arg_str(args->ap, args->current++);
	size = ft_strlen(str);
	if (fmt->precision != 0 && fmt->precision < size)
		size = fmt->precision;
	padding = (fmt->width != 0 && fmt->width > size) ? fmt->width - size : 0;
	if (!(fmt->flags & F_MINUS))
		buff_addnchar(buff, ' ', padding);
	buff_addnstr(buff, str, size);
	if (fmt->flags & F_MINUS)
		buff_addnchar(buff, ' ', padding);
}
