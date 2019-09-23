#include <stdlib.h>

#include "ft_printf.h"
#include "ft_printf_core.h"

int				ft_vprintf(const char *format, va_list ap)
{
	return (ft_vfdprintf(1, format, ap));
}

int				ft_vfdprintf(int fd, const char *format, va_list ap)
{
	t_buffer	buff;
	char		*str;
	
	if (!(str = (char*)malloc(BUFF_SIZE * sizeof(char))))
		return (-1);
	buff_init(&buff, FD, fd, str, BUFF_SIZE);
	ft_printf__(&buff, format, ap);
	free(str);
	return (buff.total);
}

int				ft_vsprintf(char *str, const char *format, va_list ap)
{
	t_buffer	buff;

	buff_init(&buff, STR, 0, str, 0);
	ft_printf__(&buff, format, ap);
	return (buff.total);
}

int				ft_vsnprintf(char *str, size_t size, const char *format,
					va_list ap)
{
	t_buffer	buff;

	buff_init(&buff, NSTR, 0, str, size);
	ft_printf__(&buff, format, ap);
	return (buff.total);
}
