/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_exception.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:57:38 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/07 15:02:02 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

int			double_exception(double d, t_fields *fields)
{
	if (d == 0.0 / 0.0)
	{
		fields->free = 0;
		fields->value = "nan";
		return (1);
	}
	else if (d == 1.0 / 0.0)
	{
		fields->free = 0;
		fields->value = "inf";
		return (1);
	}
	else if (d == -1.0 / 0.0)
	{
		fields->free = 0;
		fields->value = "-inf";
		return (1);
	}
	return (0);
}

int			ldouble_exception(long double d, t_fields *fields)
{
	if (d == 0.0L / 0.0L)
	{
		fields->free = 0;
		fields->value = "nan";
		return (1);
	}
	else if (d == 1.0L / 0.0L)
	{
		fields->free = 0;
		fields->value = "inf";
		return (1);
	}
	else if (d == -1.0L / 0.0L)
	{
		fields->free = 0;
		fields->value = "-inf";
		return (1);
	}
	return (0);

}
