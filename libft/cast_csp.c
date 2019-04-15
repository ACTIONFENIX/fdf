/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_csp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:39:54 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/25 12:39:56 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_cast_c(va_list *params, struct s_printf_specificator *spec)
{
	char	c;
	int		bytes_printed;
	char	delim;

	if (spec->flags.flags_zero && (spec->precision || spec->flags.flags_minus))
		spec->flags.flags_zero = 0;
	delim = ' ';
	if (spec->flags.flags_zero)
		delim = '0';
	bytes_printed = 0;
	c = va_arg(*params, int);
	bytes_printed += printf_write_width(spec, &c, 1, delim);
	return (bytes_printed);
}

int	printf_cast_s(va_list *params, struct s_printf_specificator *spec)
{
	char	*str;
	int		bytes_printed;
	char	delim;

	if (spec->flags.flags_zero && (spec->precision || spec->flags.flags_minus))
		spec->flags.flags_zero = 0;
	delim = ' ';
	if (spec->flags.flags_zero)
		delim = '0';
	bytes_printed = 0;
	str = va_arg(*params, char*);
	if (!str)
		str = "(null)";
	if (spec->precision_activated == 0)
		spec->precision = ft_strlen(str);
	bytes_printed += printf_write_width(spec, str, ft_min(spec->precision,
			ft_strlen(str)), delim);
	return (bytes_printed);
}

int	printf_cast_p(va_list *params, struct s_printf_specificator *spec)
{
	unsigned long int	p;
	int					bytes_printed;
	char				delim;
	int					leading_zeros;
	char				*str;

	if (spec->flags.flags_zero && (spec->precision || spec->flags.flags_minus))
		spec->flags.flags_zero = 0;
	bytes_printed = 0;
	delim = ' ';
	p = va_arg(*params, long int);
	leading_zeros = ft_max(ft_ulltoa_base_size(p, 16) - 1, spec->precision)
			- ft_ulltoa_base_size(p, 16) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(p, 16) + leading_zeros + 2);
	ft_strcpy(str, "0x");
	ft_ulltoa_base(str + leading_zeros + 2, p, "0123456789abcdef");
	while (leading_zeros)
		str[leading_zeros-- - 1 + 2] = '0';
	if (spec->precision || !spec->precision_activated)
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), delim);
	else
		bytes_printed += printf_write_width(spec, str, 2, delim);
	free(str);
	return (bytes_printed);
}

int	printf_cast_pr(va_list *params, struct s_printf_specificator *spec)
{
	int bytes_printed;

	(void)params;
	if (spec->flags.flags_zero && (spec->precision || spec->flags.flags_minus))
		spec->flags.flags_zero = 0;
	bytes_printed = 0;
	if (spec->flags.flags_zero)
		bytes_printed += printf_write_width(spec, "%", 1, '0');
	else
		bytes_printed += printf_write_width(spec, "%", 1, ' ');
	return (bytes_printed);
}
