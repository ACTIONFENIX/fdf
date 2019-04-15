/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:07:12 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 18:07:14 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ldecimal_get_first_double_digit(long double *d)
{
	long double	d_exp10;
	int			digit;

	d_exp10 = 1.0;
	while (*d / d_exp10 >= 10)
	{
		d_exp10 *= 10;
	}
	digit = *d / d_exp10;
	*d -= d_exp10 * digit;
	return (digit);
}

long double	ft_ldecimal(long double d)
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
		ldecimal_get_first_double_digit(&d);
	}
	if (sign)
	{
		d = -d;
	}
	return (d);
}
