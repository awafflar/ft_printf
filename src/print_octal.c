/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal  .c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:43 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/03 16:21:48 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

static void		print_padding(t_buffer *buff, t_fmt *fmt, size_t size, char **s)
{
	size_t		n_zero;
	size_t		width;
	size_t		combined_size;

	combined_size = size;
	if (fmt->flags & F_SHARP && **s != '0')
		combined_size++;
	n_zero = (fmt->precision > combined_size) ? fmt->precision - size : 0;
	if (fmt->flags & F_ZERO)
		width = 0;
	else
		width = (fmt->width <= combined_size + n_zero) ? 0 :
			fmt->width - combined_size - n_zero;
	buff_addnchar(buff, ' ', width);
}

static void		print_initial_zero(t_buffer *buff, t_fmt *fmt, char *str)
{
	if (fmt->flags & F_SHARP && *str != '0')
		buff_addchar(buff, '0');
	else if (fmt->flags & F_SHARP && fmt->flags & F_PRECI &&
				fmt->precision == 0 && *str == '0')
		buff_addchar(buff, '0');
}
static void		print_zero(t_buffer *buff, t_fmt *fmt, size_t size, char *str)
{
	size_t		n_zero;
	size_t		width;
	size_t		combined_size;

	combined_size = size;
	if (fmt->flags & F_SHARP && *str != '0')
		combined_size++;
	n_zero = (fmt->precision > combined_size) ?
				fmt->precision - combined_size : 0;
	width = (fmt->width <= combined_size + n_zero) ?
				0 : fmt->width - combined_size - n_zero;
	if (fmt->flags & F_ZERO && !(fmt->flags & F_SHARP))
		buff_addnchar(buff, '0', width);
	print_initial_zero(buff, fmt, str);
	if (fmt->flags & F_ZERO && fmt->flags & F_SHARP)
		buff_addnchar(buff, '0', width);
	buff_addnchar(buff, '0', n_zero);
}

void			print_octal(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	char		*str;
	size_t		size;

	if (fmt->flags & F_PRECI && fmt->flags & F_ZERO)
		fmt->flags &= ~F_ZERO;
	str = get_str_from_oux_lenght(fmt, args, 8);
	size = (fmt->flags & F_PRECI && fmt->precision == 0 && *str == '0') ?
			0 : ft_strlen(str);
	if (fmt->width != 0 && !(fmt->flags & F_MINUS))
		print_padding(buff, fmt, size, &str);
	print_zero(buff, fmt, size, str);
	if (!(fmt->flags & F_PRECI && fmt->precision == 0 && *str == '0'))
		buff_addnstr(buff, str, size);
	if (fmt->width != 0 && fmt->flags & F_MINUS)
		print_padding(buff, fmt, size, &str);
}
