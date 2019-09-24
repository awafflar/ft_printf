#include "ft_printf_core.h"

char				*va_getarg_charptr(va_list ap, int argn)
{
	va_list			ap_tmp;
	char			*ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, char *);
	va_end(ap_tmp);
	return (ret);
}

short				*va_getarg_shortptr(va_list ap, int argn)
{
	va_list			ap_tmp;
	short			*ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, short *);
	va_end(ap_tmp);
	return (ret);
}

int					*va_getarg_intptr(va_list ap, int argn)
{
	va_list			ap_tmp;
	int				*ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, int *);
	va_end(ap_tmp);
	return (ret);
}

long				*va_getarg_longptr(va_list ap, int argn)
{
	va_list			ap_tmp;
	long			*ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, long *);
	va_end(ap_tmp);
	return (ret);
}

long long			*va_getarg_longlongptr(va_list ap, int argn)
{
	va_list			ap_tmp;
	long long		*ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, long long *);
	va_end(ap_tmp);
	return (ret);
}
