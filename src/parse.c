#include <stdarg.h>

#include "ft_printf.h"
#include "ft_printf_core.h"

static int	va_narg(va_list ap, int n)
{
	int		ret;
	va_list	list;

	va_copy(ap, list);
	while (n--)
		ret = va_arg(list, int);
	va_end(list);
	return (ret);
}

static int	p_width(t_fmt *fmt, const char **format, va_list ap, va_list apb)
{	
	int		star;
	int		tmp;

	star = 0;
	if (**format == '*')
	{
		(*format)++;
		star = 1;
	}
	if (ft_isdigit(**format))
		tmp = ft_atoi_lite(**format);
	if (**format == '$')
	{
		(*format)++;
		if (star && tmp != 0)
			fmt->width = va_narg(apb, tmp);
		else if (tmp != 0)
			fmt->arg_n = tmp;
	}
	else if (star && tmp == 0)
		fmt->width = va_arg(ap, int);
	else if (!star && tmp)
		fmt->width = tmp;
	return (1);
}

static int	p_preci(t_fmt *fmt, const char **format, va_list ap, va_list apb)
{
	int		star;

	(*format)++;
	star = 0;
	if (**format == '*')
	{
		(*format)++;
		star = 1;
	}
	if (ft_isdigit(**format))
		fmt->precision = ft_atoi_lite(**format);
	if (**format == '$')
	{
		(*format)++;
		if (star && fmt->precision != 0)
			fmt->precision = va_narg(apb, fmt->precision);
	}
	else if (star)
	{
		if (fmt->precision == 0)
			fmt->precision = va_arg(ap, int);
	}
	return (1);
}

static int	parse_loop(t_fmt *fmt, const char **format, va_list ap, va_list apb)
{
	static char		flags[5] = "+- 0#";
	int				i;

	i = -1;
	while (++i < 5)
	{
		if (**format == flags[i])
		{
			(*format)++;
			fmt->flags |= (1 << i);
			return (1);
		}
	}
	if (**format == '.')
		return (p_preci(fmt, format, ap, apb));
	if (**format == '*' || ft_isdigit(**format))
		return (p_width(fmt, format, ap, apb));
	return (0);
}

void		parse_core(t_fmt *fmt, const char **format, va_list ap, va_list apb)
{
	fmt->flags = 0;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->arg_n = 0;

	while (parse_loop(fmt, format, ap, apb))
		continue ;
}
