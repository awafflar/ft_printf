/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:52:12 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/18 13:51:07 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct		s_buffer
{
	char			buff[256];
	int				remaining;
	int				fd;
}					t_buffer;

typedef struct		s_mods
{
	int				conversion;
	int				zero;
	int				adjust;
	int				blank;
	int				sign;
	int				width;
	int				precision;
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				L;
}					t_mods;

int					ft_printf(const char *format, ...);

int					b_addchar(t_buffer buff, char c, int n);
int					b_addstr(t_buffer buff, char *s);
int					b_flush(t_buffer buff);

#endif
