/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:07:59 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 18:08:01 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ldtostr_size(unsigned long long int d, int precision)
{
	int str_size;

	str_size = 0;
	while (d >= 1)
	{
		d /= 10.0;
		++str_size;
	}
	return (str_size + precision + 3);
}

static void		ldtostr_fill_integer_part(char *str, long double *d, int *pi)
{
	int			integer_part_size;
	long double	d_cpy;

	integer_part_size = 0;
	if (ft_double_is_negative(*d))
	{
		str[*pi] = '-';
		*d = -*d;
		++*pi;
	}
	d_cpy = *d;
	if (*d < 1)
		str[(*pi)++] = '0';
	while (d_cpy >= 1)
	{
		d_cpy /= 10;
		++integer_part_size;
	}
	--integer_part_size;
	while (integer_part_size >= 0)
	{
		str[*pi] = '0' + *d / ft_pow(10, integer_part_size);
		*d -= ft_pow(10, integer_part_size) * (str[(*pi)++] - '0');
		--integer_part_size;
	}
}

static double	ldtostr_round(long double d, int precision)
{
	long double decim;

	decim = ft_decimal(d);
	if ((unsigned long long int)(decim * ft_pow(10, precision + 1)) % 10 >= 5)
	{
		if (decim < 0)
			decim -= ft_pow(10, -precision - 1) * (10 - (unsigned long long int)
					(decim * ft_pow(10, precision + 1)) % 10);
		else
			decim += ft_pow(10, -precision - 1) * (10 - (unsigned long long int)
					(decim * ft_pow(10, precision + 1)) % 10);
	}
	return (decim);
}

static void		ldtostr_fill_decimal_part(char *str, long double *d, int *pi,
											int precision)
{
	int precision_i;

	if (!precision)
	{
		str[*pi] = '0';
		++*pi;
	}
	precision_i = 1;
	while (precision_i <= precision)
	{
		str[*pi] = '0' + (int)(*d * 10);
		*d = *d * 10 - (int)(*d * 10) % 10;
		++*pi;
		++precision_i;
	}
}

char			*ldtostr(long double d, int precision)
{
	char	*str;
	int		i;

	str = ft_dtostr_isnan_or_inf(d);
	if (str)
		return (str);
	str = (char*)malloc(ldtostr_size(d, precision) + 1);
	i = 0;
	if (ldtostr_round(d, precision) >= 1)
		d += 1;
	ldtostr_fill_integer_part(str, &d, &i);
	str[i++] = '.';
	d = ldtostr_round(d, precision);
	if (d >= 1)
		d -= 1;
	ldtostr_fill_decimal_part(str, &d, &i, precision);
	str[i] = '\0';
	return (str);
}
