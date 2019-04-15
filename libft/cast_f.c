/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:12:56 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:12:58 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_write_f(va_list *params, struct s_printf_specificator *spec)
{
	double	d;
	int		bytes_printed;
	char	*str;
	int		str_out;

	bytes_printed = 0;
	d = va_arg(*params, double);
	if (spec->precision == 0 && spec->precision_activated == 0)
		spec->precision = 6;
	str = dtostr(d, spec->precision);
	str_out = ft_strlen(str);
	if (spec->precision == 0)
		str_out -= 2;
	if (spec->flags.flags_sharp && spec->precision == 0)
		str_out += 1;
	bytes_printed += printf_write_width(spec, str, str_out, ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_lf(va_list *params, struct s_printf_specificator *spec)
{
	long double	d;
	int			bytes_printed;
	char		*str;
	int			str_out;

	bytes_printed = 0;
	d = va_arg(*params, long double);
	if (spec->precision == 0 && spec->precision_activated == 0)
		spec->precision = 6;
	str = ldtostr(d, spec->precision);
	str_out = ft_strlen(str);
	if (spec->precision == 0)
		str_out -= 2;
	if (spec->flags.flags_sharp && spec->precision == 0)
		str_out += 1;
	bytes_printed += printf_write_width(spec, str, str_out, ' ');
	free(str);
	return (bytes_printed);
}

int	printf_cast_f(va_list *params, struct s_printf_specificator *spec)
{
	if (ft_strcmp(spec->modifier, "l") == 0)
		return (printf_write_lf(params, spec));
	else if (ft_strcmp(spec->modifier, "L") == 0)
		return (printf_write_lf(params, spec));
	else
		return (printf_write_f(params, spec));
}
