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

void		buff_init(t_buffer *buff, t_bufftype type, int fd,
				char *str, size_t size)
{
	buff->type = type;
	buff->fd = fd;
	buff->str = str;
	buff->size = (buff->type == NSTR ? size - 1 : size);
	buff->pos = 0;
	buff->total = 0;
}

void		buff_addchar(t_buffer *buff, const char c)
{
	buff->total++;
	if (buff->pos == buff->size && buff->type != STR)
	{
		if (buff->type == NSTR)
			return ;
		buff_flush(buff);
	}
	buff->str[buff->pos++] = c;
}

void		buff_addnchar(t_buffer *buff, const char c, size_t n)
{
	while (n--)
		buff_addchar(buff, c);
}

void		buff_addstr(t_buffer *buff, const char *s)
{
	while (*s)
		buff_addchar(buff, *s++);
}

void		buff_addnstr(t_buffer *buff, const char *s, size_t n)
{
	while (n-- && *s)
		buff_addchar(buff, *s++);
}

void		buff_flush(t_buffer *buff)
{
	if (buff->type == FD)
	{
		write(buff->fd, buff->str, buff->pos);
		buff->pos = 0;
	}
	else
		buff->str[buff->pos] = '\0';
}
