/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:52:52 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/08 19:25:51 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_overflow_val(int sign)
{
	if (sign)
		return (-1);
	return (0);
}

static int	ft_get_int(const char *str, int sign)
{
	long long int	ret_val;
	size_t			i;

	i = 0;
	ret_val = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (ret_val > 0 && ret_val + str[i] <= 0)
			return (ft_get_overflow_val(sign));
		ret_val += str[i] - '0';
		++i;
		if (str[i] && ft_isdigit(str[i]) &&
				ret_val > 0 && ret_val * 10 < 0)
			return (ft_get_overflow_val(sign));
		if (str[i] && ft_isdigit(str[i]))
			ret_val *= 10;
	}
	ret_val *= sign;
	return (ret_val);
}

int			ft_atoi(const char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		++i;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	return (ft_get_int(str + i, sign));
}
