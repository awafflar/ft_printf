#include "ft_printf.h"
#include "ft_printf_core.h"

static void		printf_switch(t_buffer *buff, t_fmt *fmt,
					const char *format, t_args *args)
{
	static char	flags[3] = "%sd";
	static void (*fun[3])(t_buffer *, t_fmt *, t_args *) = 
				{
					print_modulo, print_str, print_decimal
				};
	int			i;

	i = -1;
	while (++i < 3)
	{
		if (*format == flags[i])
		{
			fun[i](buff, fmt, args);
			break ;
		}
	}
}

void			ft_printf__(t_buffer *buff, const char *format, va_list ap)
{
	t_fmt		fmt;
	t_args		args;

	va_copy(args.ap, ap);
	args.current = 1;
	while (*format)
	{
		if (*format != '%')
			buff_addchar(buff, *format);
		else
		{
			format++;
			parse_core(&fmt, &format, &args);
			printf_switch(buff, &fmt, format, &args);
		}
		format++;
	}
	buff_flush(buff);
	va_end(args.ap);
}

