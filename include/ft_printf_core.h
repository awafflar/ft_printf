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
char				*ft_lltostr(long long n, char *str);
char				*ft_ulltostr(long long n, char *str, int base,
						char *digits);

void				buff_init(t_buffer *buff, t_bufftype type, int fd,
						char *str, size_t size);
void				buff_addchar(t_buffer *buff, const char c);
void				buff_addnchar(t_buffer *buff, const char c, size_t n);
void				buff_addstr(t_buffer *buff, const char *s);
void				buff_addnstr(t_buffer *buff, const char *s, size_t n);
void				buff_flush(t_buffer *buff);

void				ft_printf__(t_buffer *buff, const char *format,
						va_list ap);

#endif
