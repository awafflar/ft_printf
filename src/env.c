#include	"ft_printf.h"

t_buffer			*get_buffer()
{
	static int		init = 0;
	static t_buffer instance;

	if (init == 0)
	{
		init = 1;
		buff_init(&instance);
	}
	return (&instance);
}
