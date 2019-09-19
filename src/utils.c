/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:20:27 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/18 14:22:41 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(const char *s)
{
	const char	*s1;

	s1 = s;
	while (*s1++);
	return (s1 - s);
}

int				ft_atoi_lite(const char **str)
{
	int		ret;

	ret = 0;
	while (**str >= '0' && **str <= '9')
		ret = ret * 10 + *((*str)++) - '0';
	return (ret);
}
