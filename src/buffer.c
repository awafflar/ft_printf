/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:34:33 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/19 15:07:08 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

void			buff_init(t_buffer *buff)
{
	buff->pos = 0;
	buff->remaining = BUFF_SIZE;
	buff->fd = 1;
	buff->total = 0;
}

void			buff_addchar(t_buffer *buff, char c)
{
	if(!buff->remaining)
		b_flush(buff);
	buff->str[buff->pos++] = c;
	buff->remaining--;
}

void			buff_addnchar(t_buffer *buff, char c, int n)
{
	while (n--)
		b_addchar(buff, c);
}

void			buff_addstr(t_buffer *buff, char *str)
{
	while (*str)
		buff_addchar(buff, *str++);
}

void			buff_flush(t_buffer *buff)
{
	write(buff->fd, buff->str, buff->pos);
	buff->total += buff->pos;
	buff->pos = 0;
	buff->remaining = BUFF_SIZE;
}
