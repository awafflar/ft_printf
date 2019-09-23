#include "ft_printf_core.h"

void			print_modulo(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	(void)fmt;
	(void)args;
	buff_addchar(buff, '%');
}
