/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:06:02 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/02 18:46:02 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

static void		print_sharp(t_buffer *buff, t_fmt *fmt)
{
	if (fmt->uppercase == 1)
		buff_addnstr(buff, "0X", 2);
	else
		buff_addnstr(buff, "0x", 2);
}

static void		print_padding(t_buffer *buff, t_fmt *fmt, size_t size, char **s)
{
	size_t		n_zero;
	size_t		width;
	size_t		combined_size;

	combined_size = size;
	if (fmt->flags & F_SHARP && **s != '0')
		combined_size += 2;
	n_zero = (fmt->precision > size) ? fmt->precision - size : 0;
	if (fmt->flags & F_ZERO)
		width = 0;
	else
		width = (fmt->width <= combined_size + n_zero) ? 0 :
			fmt->width - combined_size - n_zero;
	if (fmt->flags & F_PRECI && fmt->precision == 0 && **s == '0' && width > 0)
		width++;
	buff_addnchar(buff, ' ', width);
}

static void		print_zero(t_buffer *buff, t_fmt *fmt, size_t size, char *str)
{
	size_t		n_zero;
	size_t		width;
	size_t		combined_size;

	combined_size = size;
	if (fmt->flags & F_SHARP && *str != '0')
		combined_size += 2;
	n_zero = (fmt->precision > size) ? fmt->precision - size : 0;
	width = (fmt->width <= combined_size + n_zero) ?
				0 : fmt->width - combined_size - n_zero;
	if (fmt->flags & F_ZERO)
		buff_addnchar(buff, '0', width);
	if (fmt->flags & F_SHARP && *str != '0')
		print_sharp(buff, fmt);
	buff_addnchar(buff, '0', n_zero);
}

void			print_hexa(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	char		*str;
	size_t		size;

	if (fmt->flags & F_PRECI && fmt->flags & F_ZERO)
		fmt->flags &= ~F_ZERO;
	str = get_str_from_oux_lenght(fmt, args);
	size = ft_strlen(str);
	if (fmt->width != 0 && !(fmt->flags & F_MINUS))
		print_padding(buff, fmt, size, &str);
	print_zero(buff, fmt, size, str);
	if (!(fmt->flags & F_PRECI && fmt->precision == 0 && *str == '0'))
		buff_addnstr(buff, str, size);
	if (fmt->width != 0 && fmt->flags & F_MINUS)
		print_padding(buff, fmt, size, &str);
}
