/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:52:12 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/18 15:03:07 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE 10

typedef struct		s_buffer
{
	char			str[BUFF_SIZE];
	int				pos;
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

int					ft_strlen(const char *s);

void				b_init(t_buffer *buff);
void				b_addchar(t_buffer *buff, const char c, int n);
void				b_addstr(t_buffer *buff, const char *s);
void				b_addnstr(t_buffer *buff, const char *s, int n);
void				b_flush(t_buffer *buff);

#endif
