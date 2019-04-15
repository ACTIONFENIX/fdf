/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:13:03 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:13:05 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_write_hho(va_list *params, struct s_printf_specificator *spec)
{
	unsigned char	o;
	int				count;
	char			delim;
	int				leading_zeros;
	char			*str;

	count = 0;
	if ((delim = ' ') && spec->flags.flags_zero)
		delim = '0';
	o = va_arg(*params, int);
	leading_zeros = ft_max(ft_ulltoa_base_size(o, 8) - 1, spec->precision) -
					ft_ulltoa_base_size(o, 8) + 1;
	if ((leading_zeros == 0) && (spec->flags.flags_sharp))
		++leading_zeros;
	if (leading_zeros < 0)
		leading_zeros = 0;
	str = (char *)malloc(ft_ulltoa_base_size(o, 8) + leading_zeros);
	str[ft_ulltoa_base_size(o, 8) + leading_zeros - 1] = 0;
	ft_ulltoa_base(str + leading_zeros, o, "01234567");
	while (leading_zeros)
		str[leading_zeros-- - 1] = '0';
	count += printf_write_width(spec, str, ft_strlen(str), delim);
	free(str);
	return (count);
}

int	printf_write_ho(va_list *params, struct s_printf_specificator *spec)
{
	unsigned short	o;
	int				count;
	char			delim;
	int				leading_zeros;
	char			*str;

	count = 0;
	if ((delim = ' ') && spec->flags.flags_zero)
		delim = '0';
	o = va_arg(*params, int);
	leading_zeros = ft_max(ft_ulltoa_base_size(o, 8) - 1, spec->precision) -
					ft_ulltoa_base_size(o, 8) + 1;
	if ((leading_zeros == 0) && (spec->flags.flags_sharp))
		++leading_zeros;
	if (leading_zeros < 0)
		leading_zeros = 0;
	str = (char *)malloc(ft_ulltoa_base_size(o, 8) + leading_zeros);
	str[ft_ulltoa_base_size(o, 8) + leading_zeros - 1] = 0;
	ft_ulltoa_base(str + leading_zeros, o, "01234567");
	while (leading_zeros)
		str[leading_zeros-- - 1] = '0';
	count += printf_write_width(spec, str, ft_strlen(str), delim);
	free(str);
	return (count);
}

int	printf_write_lo(va_list *params, struct s_printf_specificator *spec)
{
	unsigned long int	o;
	int					count;
	char				delim;
	int					leading_zeros;
	char				*str;

	count = 0;
	if ((delim = ' ') && spec->flags.flags_zero)
		delim = '0';
	o = va_arg(*params, long int);
	leading_zeros = ft_max(ft_ulltoa_base_size(o, 8) - 1, spec->precision) -
					ft_ulltoa_base_size(o, 8) + 1;
	if ((leading_zeros == 0) && (spec->flags.flags_sharp))
		++leading_zeros;
	if (leading_zeros < 0)
		leading_zeros = 0;
	str = (char *)malloc(ft_ulltoa_base_size(o, 8) + leading_zeros);
	str[ft_ulltoa_base_size(o, 8) + leading_zeros - 1] = 0;
	ft_ulltoa_base(str + leading_zeros, o, "01234567");
	while (leading_zeros)
		str[leading_zeros-- - 1] = '0';
	count += printf_write_width(spec, str, ft_strlen(str), delim);
	free(str);
	return (count);
}

int	printf_write_llo(va_list *params, struct s_printf_specificator *spec)
{
	unsigned long long int	o;
	int						count;
	char					delim;
	int						leading_zeros;
	char					*str;

	count = 0;
	if ((delim = ' ') && spec->flags.flags_zero)
		delim = '0';
	o = va_arg(*params, long long int);
	leading_zeros = ft_max(ft_ulltoa_base_size(o, 8) - 1, spec->precision) -
					ft_ulltoa_base_size(o, 8) + 1;
	if ((leading_zeros == 0) && (spec->flags.flags_sharp))
		++leading_zeros;
	if (leading_zeros < 0)
		leading_zeros = 0;
	str = (char *)malloc(ft_ulltoa_base_size(o, 8) + leading_zeros);
	str[ft_ulltoa_base_size(o, 8) + leading_zeros - 1] = 0;
	ft_ulltoa_base(str + leading_zeros, o, "01234567");
	while (leading_zeros)
		str[leading_zeros-- - 1] = '0';
	count += printf_write_width(spec, str, ft_strlen(str), delim);
	free(str);
	return (count);
}

int	printf_write_o(va_list *params, struct s_printf_specificator *spec)
{
	unsigned int	o;
	int				count;
	char			delim;
	int				leading_zeros;
	char			*str;

	count = 0;
	if ((delim = ' ') && spec->flags.flags_zero)
		delim = '0';
	o = va_arg(*params, int);
	leading_zeros = ft_max(ft_ulltoa_base_size(o, 8) - 1, spec->precision) -
			ft_ulltoa_base_size(o, 8) + 1;
	if ((leading_zeros == 0) && (spec->flags.flags_sharp))
		++leading_zeros;
	if (leading_zeros < 0)
		leading_zeros = 0;
	str = (char *)malloc(ft_ulltoa_base_size(o, 8) + leading_zeros);
	str[ft_ulltoa_base_size(o, 8) + leading_zeros - 1] = 0;
	ft_ulltoa_base(str + leading_zeros, o, "01234567");
	while (leading_zeros)
		str[leading_zeros-- - 1] = '0';
	count += printf_write_width(spec, str, ft_strlen(str), delim);
	free(str);
	return (count);
}
