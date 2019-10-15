/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:20:27 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/15 11:00:28 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int			ft_atoi_lite(const char **str)
{
	int		ret;

	ret = 0;
	while (ft_isdigit(**str))
		ret = ret * 10 + *((*str)++) - '0';
	return (ret);
}

char		*ft_lltostr(long long n)
{
	static char		buff[21];
	char			*ret;

	ret = buff + 20;
	*ret = '\0';
	if (n == 0)
		*--ret = '0';
	else if (n < 0)
	{
		while (n)
		{
			*--ret = (char)('0' - (n % 10));
			n /= 10;
		}
		*--ret = '-';
	}
	else
		while (n)
		{
			*--ret = (char)('0' + n % 10);
			n /= 10;
		}
	return (ret);
}

char		*ft_ulltostr_base(unsigned long long n, unsigned int base,
				char *digits)
{
	static char		buff[65];
	char			*ret;

	ret = buff + 64;
	*ret = '\0';
	if (n == 0)
		*--ret = digits[0];
	else
		while (n)
		{
			*--ret = digits[n % base];
			n /= base;
		}
	return (ret);
}
