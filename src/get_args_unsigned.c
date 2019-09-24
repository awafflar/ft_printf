#include "ft_printf_core.h"

/*
unsigned char			va_getarg_uchar(va_list ap, int argn)
{
	va_list				ap_tmp;
	unsigned char		ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, unsigned char);
	va_end(ap_tmp);
	return (ret);
}

unsigned short			va_getarg_ushort(va_list ap, int argn)
{
	va_list				ap_tmp;
	unsigned short		ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, unsigned short);
	va_end(ap_tmp);
	return (ret);
}
*/

unsigned int			va_getarg_uint(va_list ap, int argn)
{
	va_list				ap_tmp;
	unsigned int		ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, unsigned int);
	va_end(ap_tmp);
	return (ret);
}

unsigned long			va_getarg_ulong(va_list ap, int argn)
{
	va_list				ap_tmp;
	unsigned long		ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, unsigned long);
	va_end(ap_tmp);
	return (ret);
}

unsigned long long		va_getarg_ulonglong(va_list ap, int argn)
{
	va_list				ap_tmp;
	unsigned long long	ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, unsigned long long);
	va_end(ap_tmp);
	return (ret);
}
