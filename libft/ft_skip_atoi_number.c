/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_atoi_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:30:02 by myaremen          #+#    #+#             */
/*   Updated: 2019/03/14 17:30:36 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*skip_atoi_number(const char *str)
{
	if (*str == '+' || *str == '-')
	{
		++str;
	}
	while (ft_isdigit(*str))
	{
		++str;
	}
	return (str);
}
