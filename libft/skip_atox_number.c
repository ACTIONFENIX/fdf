/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_atox_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:05:33 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 16:05:35 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*skip_atox_number(char *str)
{
	if (*str == '0')
	{
		++str;
	}
	if (*str == 'x' || *str == 'X')
	{
		++str;
	}
	while (is_atox_digit(*str))
	{
		++str;
	}
	return (str);
}
