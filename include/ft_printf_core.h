#ifndef FT_PRINTF_CORE_H
# define FT_PRINTF_CORE_H

#include <stdarg.h>

int		ft_printf_core(int fd, const char *format, va_list ap);

void	parse_core(t_fmt *fmt, const char **format, va_list ap, va_list apb);

#endif
