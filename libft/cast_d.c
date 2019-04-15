/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:10:21 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:10:23 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_write_hhd(va_list *params, struct s_printf_specificator *spec)
{
	char		d;
	int			bytes_printed;
	char		*str;
	int			leading_zeros;

	bytes_printed = 0;
	d = va_arg(*params, int);
	if (spec->flags.flags_space && d > 0)
		spec->flags.flags_plus = 1;
	leading_zeros = (spec->width - printf_numbers_count(d) -
			(spec->flags.flags_plus || spec->flags.flags_space || d < 0)) *
					(spec->flags.flags_zero);
	if (spec->precision_activated)
		leading_zeros = spec->precision - printf_numbers_count(d);
	str = ft_printf_lltoa(d, leading_zeros, spec->flags.flags_plus);
	if (spec->flags.flags_space && d > 0)
		str[0] = ' ';
	if (d == 0 && spec->precision == 0 && spec->precision_activated == 1)
		bytes_printed += printf_write_width(spec, "", 0, ' ');
	else
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_hd(va_list *params, struct s_printf_specificator *spec)
{
	short int		d;
	int				bytes_printed;
	char			*str;
	int				leading_zeros;

	bytes_printed = 0;
	d = va_arg(*params, int);
	if (spec->flags.flags_space && d > 0)
		spec->flags.flags_plus = 1;
	leading_zeros = (spec->width - printf_numbers_count(d) -
			(spec->flags.flags_plus || spec->flags.flags_space || d < 0)) *
					(spec->flags.flags_zero);
	if (spec->precision_activated)
		leading_zeros = spec->precision - printf_numbers_count(d);
	str = ft_printf_lltoa(d, leading_zeros, spec->flags.flags_plus);
	if (spec->flags.flags_space && d > 0)
		str[0] = ' ';
	if (d == 0 && spec->precision == 0 && spec->precision_activated == 1)
		bytes_printed += printf_write_width(spec, "", 0, ' ');
	else
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_ld(va_list *params, struct s_printf_specificator *spec)
{
	long int		d;
	int				bytes_printed;
	char			*str;
	int				leading_zeros;

	bytes_printed = 0;
	d = va_arg(*params, long int);
	if (spec->flags.flags_space && d > 0)
		spec->flags.flags_plus = 1;
	leading_zeros = (spec->width - printf_numbers_count(d) -
			(spec->flags.flags_plus || spec->flags.flags_space || d < 0)) *
					(spec->flags.flags_zero);
	if (spec->precision_activated)
		leading_zeros = spec->precision - printf_numbers_count(d);
	str = ft_printf_lltoa(d, leading_zeros, spec->flags.flags_plus);
	if (spec->flags.flags_space && d > 0)
		str[0] = ' ';
	if (d == 0 && spec->precision == 0 && spec->precision_activated == 1)
		bytes_printed += printf_write_width(spec, "", 0, ' ');
	else
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_lld(va_list *params, struct s_printf_specificator *spec)
{
	long long int		d;
	int					bytes_printed;
	char				*str;
	int					leading_zeros;

	bytes_printed = 0;
	d = va_arg(*params, long long int);
	if (spec->flags.flags_space && d > 0)
		spec->flags.flags_plus = 1;
	leading_zeros = (spec->width - printf_numbers_count(d) -
			(spec->flags.flags_plus || spec->flags.flags_space || d < 0)) *
					(spec->flags.flags_zero);
	if (spec->precision_activated)
		leading_zeros = spec->precision - printf_numbers_count(d);
	str = ft_printf_lltoa(d, leading_zeros, spec->flags.flags_plus);
	if (spec->flags.flags_space && d > 0)
		str[0] = ' ';
	if (d == 0 && spec->precision == 0 && spec->precision_activated == 1)
		bytes_printed += printf_write_width(spec, "", 0, ' ');
	else
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_d(va_list *params, struct s_printf_specificator *spec)
{
	int		d;
	int		bytes_printed;
	char	*str;
	int		leading_zeros;

	bytes_printed = 0;
	d = va_arg(*params, int);
	if (spec->flags.flags_space && d > 0)
		spec->flags.flags_plus = 1;
	leading_zeros = (spec->width - printf_numbers_count(d) -
			(spec->flags.flags_plus || spec->flags.flags_space || d < 0)) *
					(spec->flags.flags_zero);
	if (spec->precision_activated)
		leading_zeros = spec->precision - printf_numbers_count(d);
	str = ft_printf_lltoa(d, leading_zeros, spec->flags.flags_plus);
	if (spec->flags.flags_space && d > 0)
		str[0] = ' ';
	if (d == 0 && spec->precision == 0 && spec->precision_activated == 1)
		bytes_printed += printf_write_width(spec, "", 0, ' ');
	else
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), ' ');
	free(str);
	return (bytes_printed);
}
