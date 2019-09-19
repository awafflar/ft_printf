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

# define BUFF_SIZE	10
# define F_PLUS		1
# define F_MINUS	2
# define F_SPACE	4
# define F_ZERO		8
# define F_SHARP	16

typedef struct		s_buffer
{
	char			str[BUFF_SIZE];
	int				pos;
	int				remaining;
	int				fd;
	int				total;
}					t_buffer;

typedef struct		s_format
{
	char			flags;
	int				width;
	int				precision;
	int				arg_n;
}					t_format;

int					ft_printf(const char *format, ...);
int					ft_printf_fd(int fd, const char *format, ...);
void				parse_mods(t_format *fmt, const char *format);

int					ft_strlen(const char *s);

void				buff_init(t_buffer *buff);
void				buff_addchar(t_buffer *buff, const char c, int n);
void				buff_addnchar(t_buffer *buff, const char c);
void				buff_addstr(t_buffer *buff, const char *s);
void				buff_flush(t_buffer *buff);

t_buffer			*get_buff();

#endif
