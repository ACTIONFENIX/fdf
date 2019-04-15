/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:13:55 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/06 15:01:00 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_number(long long int n, char *str, size_t len)
{
	size_t			i;
	long long int	lower_bound;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		++i;
	}
	lower_bound = 1;
	while (lower_bound <= n)
		lower_bound *= 10;
	if (lower_bound >= 10)
		lower_bound /= 10;
	while (i < len)
	{
		str[i] = '0' + n / lower_bound;
		n -= n / lower_bound * lower_bound;
		lower_bound /= 10;
		++i;
	}
	str[len] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				n_cpy;
	unsigned char	len;

	len = 0;
	n_cpy = n;
	while (n_cpy)
	{
		n_cpy /= 10;
		++len;
	}
	if (n <= 0)
		++len;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (ft_get_number(n, str, len));
}
