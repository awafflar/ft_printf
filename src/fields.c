/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:09:28 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/06 18:28:15 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void		fields_init(t_fields *f)
{
	f->prefix = "";
	f->is_precision_padding = 1;
	f->free = 0;
	f->has_limit = 0;
}
