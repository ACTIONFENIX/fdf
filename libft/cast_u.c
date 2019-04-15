/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:13:11 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:13:13 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_write_hhu(va_list *params, struct s_printf_specificator *spec)
{
	unsigned char	u;
	int				bytes_printed;
	char			delim;
	int				leading_zeros;
	char			*str;

	bytes_printed = 0;
	delim = ' ';
	if (spec->flags.flags_zero)
		delim = '0';
	u = va_arg(*params, int);
	leading_zeros = ft_max(ft_ulltoa_base_size(u, 10) - 1, spec->precision) -
					ft_ulltoa_base_size(u, 10) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(u, 10) + leading_zeros);
	str[ft_ulltoa_base_size(u, 10) + leading_zeros - 1] = 0;
	ft_ulltoa_base(str + leading_zeros, u, "0123456789");
	while (leading_zeros)
		str[leading_zeros-- - 1] = '0';
	if (spec->precision || !spec->precision_activated)
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), delim);
	else
		bytes_printed += printf_write_width(spec, str, spec->flags.flags_sharp,
				delim);
	free(str);
	return (bytes_printed);
}

int	printf_write_hu(va_list *params, struct s_printf_specificator *spec)
{
	unsigned short int	u;
	int					bytes_printed;
	char				delim;
	int					leading_zeros;
	char				*str;

	bytes_printed = 0;
	delim = ' ';
	if (spec->flags.flags_zero)
		delim = '0';
	u = va_arg(*params, int);
	leading_zeros = ft_max(ft_ulltoa_base_size(u, 10) - 1, spec->precision) -
					ft_ulltoa_base_size(u, 10) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(u, 10) + leading_zeros);
	str[ft_ulltoa_base_size(u, 10) + leading_zeros - 1] = 0;
	ft_ulltoa_base(str + leading_zeros, u, "0123456789");
	while (leading_zeros)
		str[leading_zeros-- - 1] = '0';
	if (spec->precision || !spec->precision_activated)
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), delim);
	else
		bytes_printed += printf_write_width(spec, str, spec->flags.flags_sharp,
				delim);
	free(str);
	return (bytes_printed);
}

int	printf_write_lu(va_list *params, struct s_printf_specificator *spec)
{
	unsigned long int	u;
	int					bytes_printed;
	char				delim;
	int					leading_zeros;
	char				*str;

	bytes_printed = 0;
	delim = ' ';
	if (spec->flags.flags_zero)
		delim = '0';
	u = va_arg(*params, long int);
	leading_zeros = ft_max(ft_ulltoa_base_size(u, 10) - 1, spec->precision) -
					ft_ulltoa_base_size(u, 10) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(u, 10) + leading_zeros);
	str[ft_ulltoa_base_size(u, 10) + leading_zeros - 1] = 0;
	ft_ulltoa_base(str + leading_zeros, u, "0123456789");
	while (leading_zeros)
		str[leading_zeros-- - 1] = '0';
	if (spec->precision || !spec->precision_activated)
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), delim);
	else
		bytes_printed += printf_write_width(spec, str, spec->flags.flags_sharp,
				delim);
	free(str);
	return (bytes_printed);
}

int	printf_write_llu(va_list *params, struct s_printf_specificator *spec)
{
	unsigned long long int	u;
	int						bytes_printed;
	char					delim;
	int						leading_zeros;
	char					*str;

	bytes_printed = 0;
	delim = ' ';
	if (spec->flags.flags_zero)
		delim = '0';
	u = va_arg(*params, long long int);
	leading_zeros = ft_max(ft_ulltoa_base_size(u, 10) - 1, spec->precision) -
					ft_ulltoa_base_size(u, 10) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(u, 10) + leading_zeros);
	str[ft_ulltoa_base_size(u, 10) + leading_zeros - 1] = 0;
	ft_ulltoa_base(str + leading_zeros, u, "0123456789");
	while (leading_zeros)
		str[leading_zeros-- - 1] = '0';
	if (spec->precision || !spec->precision_activated)
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), delim);
	else
		bytes_printed += printf_write_width(spec, str, spec->flags.flags_sharp,
				delim);
	free(str);
	return (bytes_printed);
}

int	printf_write_u(va_list *params, struct s_printf_specificator *spec)
{
	unsigned int	u;
	int				bytes_printed;
	char			delim;
	int				leading_zeros;
	char			*str;

	bytes_printed = 0;
	delim = ' ';
	if (spec->flags.flags_zero)
		delim = '0';
	u = va_arg(*params, int);
	leading_zeros = ft_max(ft_ulltoa_base_size(u, 10) - 1, spec->precision) -
			ft_ulltoa_base_size(u, 10) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(u, 10) + leading_zeros);
	str[ft_ulltoa_base_size(u, 10) + leading_zeros - 1] = 0;
	ft_ulltoa_base(str + leading_zeros, u, "0123456789");
	while (leading_zeros)
		str[leading_zeros-- - 1] = '0';
	if (spec->precision || !spec->precision_activated)
		bytes_printed += printf_write_width(spec, str, ft_strlen(str), delim);
	else
		bytes_printed += printf_write_width(spec, str, spec->flags.flags_sharp,
				delim);
	free(str);
	return (bytes_printed);
}
