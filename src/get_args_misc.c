#include "ft_printf_core.h"

char				*va_getarg_str(va_list ap, int argn)
{
	va_list			ap_tmp;
	char			*ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, char *);
	va_end(ap_tmp);
	return (ret);
}

void				*va_getarg_ptr(va_list ap, int argn)
{
	va_list			ap_tmp;
	void			*ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, void *);
	va_end(ap_tmp);
	return (ret);
}

double				va_getarg_double(va_list ap, int argn)
{
	va_list			ap_tmp;
	double			ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, double);
	va_end(ap_tmp);
	return (ret);
}
