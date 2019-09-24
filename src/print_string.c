#include "ft_printf_core.h"

void		print_str(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	char	*str;
	size_t	size;
	size_t	padding;

	str = va_getarg_str(args->ap, args->current++);
	size = ft_strlen(str);
	if (fmt->flags & F_PRECI && fmt->precision < size)
		size = fmt->precision;
	padding = (fmt->width != 0 && fmt->width > size) ? fmt->width - size : 0;
	if (!(fmt->flags & F_MINUS))
		buff_addnchar(buff, ' ', padding);
	buff_addnstr(buff, str, size);
	if (fmt->flags & F_MINUS)
		buff_addnchar(buff, ' ', padding);
}
