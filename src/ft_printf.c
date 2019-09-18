/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:38:59 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/18 15:58:35 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_buffer	*buff;

	if (!(buff = malloc(sizeof(t_buffer))))
		exit(EXIT_FAILURE);
	b_init(buff);
	b_addchar(buff, '?', 12);
	b_addstr(buff, format);
	b_flush(buff);
	return (0);
}
