/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:44:43 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 13:44:45 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double base, int exponent)
{
	double	res;
	int		minus_exp;
	int		i;

	res = 1.0;
	i = 0;
	minus_exp = exponent < 0;
	if (exponent < 0)
		exponent = -exponent;
	while (i < exponent)
	{
		res *= base;
		++i;
	}
	if (minus_exp)
		res = 1.0 / res;
	return (res);
}
