/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:03:25 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 16:03:26 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	atox_char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (c - '0');
	}
	else if (c >= 'a' && c <= 'f')
	{
		return (10 + c - 'a');
	}
	else if (c >= 'A' && c <= 'F')
	{
		return (10 + c - 'A');
	}
	else
	{
		return (0);
	}
}

static unsigned int	ft_get_uint(const char *str)
{
	unsigned int	ret_val;
	size_t			i;

	i = 0;
	ret_val = 0;
	while (str[i] && is_atox_digit(str[i]))
	{
		ret_val += atox_char_to_digit(str[i]);
		++i;
		if (str[i] && is_atox_digit(str[i]) && ret_val * 16 < ret_val)
			return (ret_val);
		if (str[i] && is_atox_digit(str[i]))
			ret_val *= 16;
	}
	return (ret_val);
}

unsigned int		ft_atox(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r')
		++i;
	if (!str[i])
		return (0);
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
	{
		str += 2;
	}
	else
	{
		return (0);
	}
	return (ft_get_uint(str + i));
}
