#ifndef FT_PRINTF_CORE_H
# define FT_PRINTF_CORE_H

#include <stdarg.h>

#include "ft_printf.h"

# define BUFF_SIZE	10
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
	char			padd;
	t_lenght		lenght;
}					t_fmt;

typedef struct		s_args
{
	va_list			ap;
	int				current;
}					t_args;

void				parse_core(t_fmt *fmt, const char **format, t_args *args);

void				print_modulo(t_buffer *buff, t_fmt *fmt, t_args *args);
void				print_str(t_buffer *buff, t_fmt *fmt, t_args *args);
void				print_decimal(t_buffer *buff, t_fmt *fmt, t_args *args);

size_t				ft_strlen(const char *s);
int					ft_isdigit(char c);
int					ft_atoi_lite(const char **str);
char				*ft_lltostr(long long n);
char				*ft_ulltostr(long long n, int base, char *digits);

void				buff_init(t_buffer *buff, t_bufftype type, int fd,
						char *str, size_t size);
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

#endif
