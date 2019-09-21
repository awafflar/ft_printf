#include "ft_printf.h"
#include "ft_printf_core.h"

void			ft_printf__(t_buffer *buff, const char *format, va_list ap)
{
	t_fmt		fmt;
	t_args		args;

	va_copy(args.ap, ap)
	args.current = 1;
	while (*format)
	{
		if (*format != '%')
			buff_addchar(buff, *format);
		else
		{
			format++;
			parse_core(&fmt, &format, &args);
		}
		format++;
	}
	buff_flush(get_buff());
	va_end(args.ap);
	return (get_buff()->total);
}

int				parse_format(t_fmt *fmt, const char *format)
{
	if (*format == '+')
	{
		fmt->flags |= PLUS;
	}
	elseif(*format == '-')
	{
		
	}
}
