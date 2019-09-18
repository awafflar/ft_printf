/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:34:33 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/18 14:07:15 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		b_init(t_buffer buff)
{
	buff.remaining = 255;
	buff.fd = 1;
}

int			b_addchar(t_buffer buff, char c, int n);
{
	if (n > buff.remaining)
		b_flush(buff);

}
