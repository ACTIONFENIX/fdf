/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:22:40 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 15:22:42 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	decimal_get_first_double_digit(double *d)
{
	double	d_exp10;
	int		digit;

	d_exp10 = 1.0;
	while (*d / d_exp10 >= 10)
	{
		d_exp10 *= 10;
	}
	digit = *d / d_exp10;
	*d -= d_exp10 * digit;
	return (digit);
}

double		ft_decimal(double d)
{
	int sign;

	sign = 0;
	if (d < 0)
	{
		d = -d;
		sign = 1;
	}
	while (d >= 1)
	{
		decimal_get_first_double_digit(&d);
	}
	if (sign)
	{
		d = -d;
	}
	return (d);
}
