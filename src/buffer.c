/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:34:33 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/18 16:09:25 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

void			b_init(t_buffer *buff)
{
	buff->pos = 0;
	buff->remaining = BUFF_SIZE;
	buff->fd = 1;
}

void			b_addchar(t_buffer *buff, const char c, int n)
{
}

void			b_addstr(t_buffer *buff, const char *s)
{
	int		len;

	len = ft_strlen(s);
	while (*s)
	{
		if (len > buff->remaining)
		{
			b_addnstr(buff, s, buff->remaining);
			s += buff->remaining;
			len -= buff->remaining;
			b_flush(buff);
		}
		else
		{
			b_addnstr(buff, s, len);
			buff->pos += len;
			buff->remaining -= len;
			s += len;
		}
	}
}

void			b_addnstr(t_buffer *buff, const char *s, int n)
{
	int		i;

	i  = buff->pos;
	while (n-- >= 0)
		buff->str[i++] = *s++;
	buff->remaining -= n;
	buff->pos += n;
}

void			b_flush(t_buffer *buff)
{
	write(buff->fd, buff->str, ft_strlen(buff->str));
	buff->pos = 0;
	buff->remaining = BUFF_SIZE;
}
