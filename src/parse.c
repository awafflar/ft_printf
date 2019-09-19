#include "ft_printf.h"

int		p_plus(t_format *fmt, const char **format)
{
	fmt->flags |= F_PLUS;
	(*format)++;
	return (1);
}

int		p_minus(t_format *fmt, const char **format)
{
	fmt->flags |= F_MINUS;
	(*format)++;
	return (1);
}

int		p_space(t_format *fmt, const char **format)
{
	fmt->flags |= F_SPACE;
	(*format)++;
	return (1);
}

int		p_zero(t_format *fmt, const char **format)
{
	fmt->flags |= F_ZERO;
	(*format)++;
	return (1);
}

int		p_sharp(t_format *fmt, const char **format)
{
	fmt->flags |= F_SHARP;
	(*format)++;
	return (1);
}
