/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:03:03 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/06 18:08:34 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf_core.h"

void		print__(t_buffer *buff, t_fields *fields)
{
	buff_addnchar(buff, fields->padd_char, fields->pre_padding_size);
	buff_addstr(buff, fields->prefix);
	buff_addnchar(buff, '0', fields->precision_padding);
	if (fields->string_limit)
		buff_addnstr(buff, fields->value, fields->limit);
	else
		buff_addstr(buff, fields->value);
	buff_addnchar(buff, fields->padd_char, fields->post_padding);
	if (fields->free)
		free(fields->value);
}
