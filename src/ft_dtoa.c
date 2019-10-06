/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:13:20 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/06 17:19:29 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf_core.h"

static char		*ft_strpcpy(char *dest, char *src)
{
	while ((*dest = *src++))
		dest++;
	return (dest); 
}

static char		*concat_double(char *int_part, char *float_part, int add_flag)
{
	char		*ret;
	char		*tmp;
	size_t		size;

	size = ft_strlen(int_part) + ft_strlen(float_part) + (size_t)add_flag + 2;
	if (!(ret = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	tmp = ret;
	if (add_flag)
		*tmp++ = '1';
	tmp = ft_strpcpy(tmp, int_part);
	*tmp++ = '.';
	ft_strpcpy(tmp, float_part);
	return (ret);
}

static int		ft_round(char *int_part, char *float_part)
{
	size_t		i;

	i = ft_strlen(float_part);
	while (i--)
	{
		if (float_part[i] != '9')
		{
			float_part[i]++;
			return (0);
		}
		float_part[i] = '0';
	}	
	i = ft_strlen(int_part);
	while (i--)
	{
		if (int_part[i] != '9')
		{
			int_part[i]++;
			return (0);
		}
		int_part[i] = '0';
	}
	return (1);
}

char			*ft_dtoa(long double d, size_t precision)
{
	char		*int_part;
	char		*float_part;
	char		*ret;
	size_t		i;
	int			add_flag;

	int_part = ft_ulltostr_base((unsigned long long)d, 10, "0123456789");
	if (!(float_part = (char *)malloc(sizeof(char) * (precision + 1))))
		return (NULL);
	d -= (double)((unsigned long long)d);
	i = 0;
	while (i < precision)
	{
		d *= 10.;
		float_part[i++] = (char)('0' + (char)d);
		d -= (double)((unsigned long long)d);
	}
	float_part[i] = '\0';
	d *= 10.;
	add_flag = (d >= 5. ? ft_round(int_part, float_part) : 0);
	ret = concat_double(int_part, float_part, add_flag);
	free(float_part);
	return (ret);
}