/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:03:35 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 14:03:37 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		dtostr_size(unsigned long long int d, int precision)
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

static void		dtostr_fill_integer_part(char *str, double *d, int *pi)
{
	int		integer_part_size;
	double	d_cpy;

	integer_part_size = 0;
	if (ft_double_is_negative(*d))
	{
		str[(*pi)++] = '-';
		*d = -*d;
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
		*d -= ft_pow(10, integer_part_size) * (str[*pi] - '0');
		--integer_part_size;
		++*pi;
	}
}

static double	dtostr_round(double d, int precision)
{
	double decim;

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

static void		dtostr_fill_decimal_part(char *str, double *d, int *pi,
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

char			*dtostr(double d, int precision)
{
	char	*str;
	int		i;

	str = ft_dtostr_isnan_or_inf(d);
	if (str)
		return (str);
	str = (char*)malloc(dtostr_size(d, precision) + 1);
	i = 0;
	if (dtostr_round(d, precision) >= 1)
		d += 1;
	dtostr_fill_integer_part(str, &d, &i);
	str[i] = '.';
	++i;
	d = dtostr_round(d, precision);
	if (d >= 1)
		d -= 1;
	dtostr_fill_decimal_part(str, &d, &i, precision);
	str[i] = '\0';
	return (str);
}
