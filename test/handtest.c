/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handtest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:34:23 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/01 16:37:21 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf_core.h"

int		main(void)
{
	printf("111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
	ft_printf("111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
	return (0);
}
