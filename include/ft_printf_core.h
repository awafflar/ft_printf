/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:14:11 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/03 14:23:19 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CORE_H
# define FT_PRINTF_CORE_H

# include <stdarg.h>

# include "ft_printf.h"

# define F_PLUS		1
# define F_MINUS	2
# define F_SPACE	4
# define F_ZERO		8
# define F_SHARP	16
# define F_PRECI	32

typedef enum		e_bufftype
{
	STR,
	NSTR,
	FD
}					t_bufftype;

typedef enum		e_lenght
{
	I,
	H,
	HH,
	L,
	LL,
	BIGL
}					t_lenght;

typedef struct		s_buffer
{
	t_bufftype		type;
	int				fd;
	char			*str;
	size_t			size;
	unsigned int	pos;
	int				total;
}					t_buffer;

typedef struct		s_fmt
{
	char			flags;
	size_t			width;
	size_t			precision;
	int				arg_n;
	t_lenght		lenght;
	int				uppercase;
	int				plus_sign;
	int				minus_sign;
}					t_fmt;

typedef struct		s_args
{
	va_list			ap;
	int				current;
}					t_args;

void				parse_core(t_fmt *fmt, const char **format, t_args *args);

void				print_modulo(t_buffer *buff, t_fmt *fmt, t_args *args);
void				print_char(t_buffer *buff, t_fmt *fmt, t_args *args);
void				print_str(t_buffer *buff, t_fmt *fmt, t_args *args);
void				print_decimal(t_buffer *buff, t_fmt *fmt, t_args *args);
void				print_hexa(t_buffer *buff, t_fmt *fmt, t_args *args);
void				print_unsigned(t_buffer *buff, t_fmt *fmt, t_args *args);
void				print_octal(t_buffer *buff, t_fmt *fmt, t_args *args);
void				print_pointer(t_buffer *buff, t_fmt *fmt, t_args *args);

size_t				ft_strlen(const char *s);
int					ft_isdigit(char c);
int					ft_atoi_lite(const char **str);
char				*ft_lltostr(long long n);
char				*ft_ulltostr_base(unsigned long long n, int base,
						char *digits);

char				*oux_uchar_tostring(t_args *args, int base, int uppercase);
char				*oux_ushort_tostring(t_args *args, int base, int uppercase);
char				*oux_uint_tostring(t_args *args, int base, int uppercase);
char				*oux_ulong_tostring(t_args *args, int base, int uppercase);
char				*oux_ulonglong_tostring(t_args *args, int base,
						int uppercase);

char				*di_char_tostring(t_args *args);
char				*di_short_tostring(t_args *args);
char				*di_int_tostring(t_args *args);
char				*di_long_tostring(t_args *args);
char				*di_longlong_tostring(t_args *args);

void				buff_init(t_buffer *buff, t_bufftype type, char *str,
						size_t size);
void				buff_addchar(t_buffer *buff, const char c);
void				buff_addnchar(t_buffer *buff, const char c, size_t n);
void				buff_addstr(t_buffer *buff, const char *s);
void				buff_addnstr(t_buffer *buff, const char *s, size_t n);
void				buff_flush(t_buffer *buff);

char				va_getarg_char(va_list ap, int argn);
short				va_getarg_short(va_list ap, int argn);
int					va_getarg_int(va_list ap, int argn);
long				va_getarg_long(va_list ap, int argn);
long long			va_getarg_longlong(va_list ap, int argn);

unsigned char		va_getarg_uchar(va_list ap, int argn);
unsigned short		va_getarg_ushort(va_list ap, int argn);
unsigned int		va_getarg_uint(va_list ap, int argn);
unsigned long		va_getarg_ulong(va_list ap, int argn);
unsigned long long	va_getarg_ulonglong(va_list ap, int argn);

char				*va_getarg_charptr(va_list ap, int argn);
short				*va_getarg_shortptr(va_list ap, int argn);
int					*va_getarg_intptr(va_list ap, int argn);
long				*va_getarg_longptr(va_list ap, int argn);
long long			*va_getarg_longlongptr(va_list ap, int argn);

char				*va_getarg_str(va_list ap, int argn);
void				*va_getarg_ptr(va_list ap, int argn);
double				va_getarg_double(va_list ap, int argn);

void				ft_printf__(t_buffer *buff, const char *format,
						va_list ap);

char				*get_str_from_oux_lenght(t_fmt *fmt, t_args *args,
						int base);
char				*get_str_from_di_lenght(t_fmt *fmt, t_args *args);
char				*get_str_from_pointer(t_args *args);
#endif
