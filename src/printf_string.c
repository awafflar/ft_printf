#include "ft_printf_core.h"

char		*get_arg_str(va_list ap, int n)
{	
	char	*ret;
	va_list	list;

	va_copy(list, ap);
	while (n--)
		ret = va_arg(list, char*);
	va_end(list);
	return (ret);
}

void		printf_str(t_fmt *fmt, t_args *args)
{
	char	*str;
	size_t	size;

	str = get_arg_str(args->ap, args->current++);
	size = ft_strlen(str);

}
