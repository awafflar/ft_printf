/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:38 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/30 17:35:18 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_printf_core.h"

static int	p_width(t_fmt *fmt, const char **format, t_args *args)
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
		tmp = ft_atoi_lite(format);
	if (**format == '$')
	{
		(*format)++;
		if (star && tmp != 0)
			fmt->width = va_getarg_int(args->ap, tmp);
		else if (tmp != 0)
			fmt->arg_n = tmp;
	}
	else if (star && tmp == 0)
		fmt->width = va_getarg_int(args->ap, args->current++);
	else if (!star && tmp)
		fmt->width = tmp;
	return (1);
}

static int	p_preci(t_fmt *fmt, const char **format, t_args *args)
{
	int		star;

	fmt->flags |= F_PRECI;
	(*format)++;
	star = 0;
	if (**format == '*')
	{
		(*format)++;
		star = 1;
	}
	if (ft_isdigit(**format))
		fmt->precision = ft_atoi_lite(format);
	if (**format == '$')
	{
		(*format)++;
		if (star && fmt->precision != 0)
			fmt->precision = va_getarg_int(args->ap, fmt->precision);
	}
	else if (star)
	{
		if (fmt->precision == 0)
			fmt->precision = va_getarg_int(args->ap, args->current++);
	}
	return (1);
}

static int	parse_loop(t_fmt *fmt, const char **format, t_args *args)
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
		return (p_preci(fmt, format, args));
	if (**format == '*' || ft_isdigit(**format))
		return (p_width(fmt, format, args));
	return (0);
}

static void	parse_lenght(t_fmt *fmt, const char **format)
{
	if (**format == 'h' || **format == 'l' || **format == 'L')
		(*format)++;
	if (**format == 'h')
	{
		if (**format == 'h')
		{
			(*format)++;
			fmt->lenght = HH;
		}
		else
			fmt->lenght = H;
	}
	else if (**format == 'l')
	{
		if (**format == 'l')
		{
			(*format)++;
			fmt->lenght = LL;
		}
		else
			fmt->lenght = L;
	}
	else if (**format == 'L')
		fmt->lenght = BIGL;
}

void		parse_core(t_fmt *fmt, const char **format, t_args *args)
{
	fmt->flags = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->arg_n = 0;
	fmt->padd = ' ';
	fmt->uppercase = 0;
	while (parse_loop(fmt, format, args))
		continue ;
	if (fmt->flags & F_PLUS)
		fmt->flags &= ~F_SPACE;
	if (fmt->flags & F_MINUS)
		fmt->flags &= ~F_ZERO;
	parse_lenght(fmt, format);
}
