/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:43 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/06 14:13:46 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

static void		print_padding(t_buffer *buff, t_fmt *fmt, size_t size, char **s)
{
	size_t		n_zero;
	size_t		width;
	size_t		combined_size;

	combined_size = (fmt->flags & F_SIGN_P || fmt->flags & F_SIGN_M ? size + 1 :
		size);
	n_zero = (fmt->precision > size) ? fmt->precision - size : 0;
	if (fmt->flags & F_ZERO)
		width = 0;
	else
		width = (fmt->width <= combined_size + n_zero) ? 0 :
			fmt->width - combined_size - n_zero;
	if (fmt->flags & F_PRECI && fmt->precision == 0 && **s == '0' && width > 0)
		width++;
	if (width == 0 && fmt->flags & F_SPACE && !(fmt->flags & F_SIGN_M))
		buff_addchar(buff, ' ');
	buff_addnchar(buff, ' ', width);
}

static void		print_sign(t_buffer *buff, t_fmt *fmt)
{
	if (fmt->flags & F_SIGN_M)
		buff_addchar(buff, '-');
	if (fmt->flags & F_PLUS && fmt->flags & F_SIGN_P)
		buff_addchar(buff, '+');
}

static void		print_zero(t_buffer *buff, t_fmt *fmt, size_t size)
{
	size_t		n_zero;
	size_t		width;
	size_t		combined_size;

	combined_size = (fmt->flags & F_SIGN_P || fmt->flags & F_SIGN_M ? size + 1 :
		size);
	n_zero = (fmt->precision > size) ? fmt->precision - size : 0;
	width = (fmt->width <= combined_size + n_zero) ?
				0 : fmt->width - combined_size - n_zero;
	if (fmt->flags & F_SPACE && fmt->flags & F_ZERO)
		width--;
	if (fmt->flags & F_ZERO)
		buff_addnchar(buff, '0', width);
	buff_addnchar(buff, '0', n_zero);
}

void			print_decimal(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	char		*str;
	size_t		size;

	if (fmt->flags & F_PRECI && fmt->flags & F_ZERO)
		fmt->flags &= ~F_ZERO;
	str = get_str_from_di_lenght(fmt, args);
	if (fmt->flags & F_PLUS && *str != '-')
		fmt->flags |= F_SIGN_P;
	if (*str == '-')
	{
		str++;
		fmt->flags |= F_SIGN_M;
	}
	size = ft_strlen(str);
	if (fmt->width != 0 && !(fmt->flags & F_MINUS))
		print_padding(buff, fmt, size, &str);
	else if (fmt->flags & F_SPACE && !(fmt->flags & F_SIGN_M))
		buff_addchar(buff, ' ');
	print_sign(buff, fmt);
	print_zero(buff, fmt, size);
	if (!(fmt->flags & F_PRECI && fmt->precision == 0 && *str == '0'))
		buff_addnstr(buff, str, size);
	if (fmt->width != 0 && fmt->flags & F_MINUS)
		print_padding(buff, fmt, size, &str);
}
