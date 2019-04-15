/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:10:46 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:10:48 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_write_hhb(va_list *params, struct s_printf_specificator *spec)
{
	unsigned char	x;
	int				bytes_printed;
	int				leading_zeros;
	char			*str;

	bytes_printed = 0;
	x = va_arg(*params, int);
	leading_zeros = printf_bx_leading_zeros(spec, x, 2);
	if (spec->precision > ft_ulltoa_base_size(x, 2))
		leading_zeros = spec->precision - ft_ulltoa_base_size(x, 2) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(x, 2) + leading_zeros + 2 *
			spec->flags.flags_sharp * (x != 0));
	str[ft_ulltoa_base_size(x, 2) + leading_zeros + 2 * spec->flags.flags_sharp
	* (x != 0) - 1] = '\0';
	if (spec->flags.flags_sharp && x)
		ft_strcat(str, "0b");
	ft_strfilln(str + spec->flags.flags_sharp * 2, '0', leading_zeros);
	ft_ulltoa_base(str + leading_zeros + 2 * spec->flags.flags_sharp * (x != 0),
			x, "01");
	if (ft_isupper(spec->cast[0]))
		ft_striter(str, printf_toupper);
	bytes_printed += printf_write_width(spec, str, (spec->precision ||
	!spec->precision_activated) ? ft_strlen(str) : 0, ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_hb(va_list *params, struct s_printf_specificator *spec)
{
	unsigned short int	x;
	int					bytes_printed;
	int					leading_zeros;
	char				*str;

	bytes_printed = 0;
	x = va_arg(*params, int);
	leading_zeros = printf_bx_leading_zeros(spec, x, 2);
	if (spec->precision > ft_ulltoa_base_size(x, 2))
		leading_zeros = spec->precision - ft_ulltoa_base_size(x, 2) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(x, 2) + leading_zeros + 2 *
			spec->flags.flags_sharp * (x != 0));
	str[ft_ulltoa_base_size(x, 2) + leading_zeros + 2 * spec->flags.flags_sharp
	* (x != 0) - 1] = '\0';
	if (spec->flags.flags_sharp && x)
		ft_strcat(str, "0b");
	ft_strfilln(str + spec->flags.flags_sharp * 2, '0', leading_zeros);
	ft_ulltoa_base(str + leading_zeros + 2 * spec->flags.flags_sharp * (x != 0),
			x, "01");
	if (ft_isupper(spec->cast[0]))
		ft_striter(str, printf_toupper);
	bytes_printed += printf_write_width(spec, str, (spec->precision ||
	!spec->precision_activated) ? ft_strlen(str) : 0, ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_lb(va_list *params, struct s_printf_specificator *spec)
{
	unsigned long int	x;
	int					bytes_printed;
	int					leading_zeros;
	char				*str;

	bytes_printed = 0;
	x = va_arg(*params, long int);
	leading_zeros = printf_bx_leading_zeros(spec, x, 2);
	if (spec->precision > ft_ulltoa_base_size(x, 2))
		leading_zeros = spec->precision - ft_ulltoa_base_size(x, 2) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(x, 2) + leading_zeros + 2 *
			spec->flags.flags_sharp * (x != 0));
	str[ft_ulltoa_base_size(x, 2) + leading_zeros + 2 * spec->flags.flags_sharp
	* (x != 0) - 1] = '\0';
	if (spec->flags.flags_sharp && x)
		ft_strcat(str, "0b");
	ft_strfilln(str + spec->flags.flags_sharp * 2, '0', leading_zeros);
	ft_ulltoa_base(str + leading_zeros + 2 * spec->flags.flags_sharp * (x != 0),
			x, "01");
	if (ft_isupper(spec->cast[0]))
		ft_striter(str, printf_toupper);
	bytes_printed += printf_write_width(spec, str, (spec->precision ||
	!spec->precision_activated) ? ft_strlen(str) : 0, ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_llb(va_list *params, struct s_printf_specificator *spec)
{
	unsigned long long int	x;
	int						bytes_printed;
	int						leading_zeros;
	char					*str;

	bytes_printed = 0;
	x = va_arg(*params, long long int);
	leading_zeros = printf_bx_leading_zeros(spec, x, 2);
	if (spec->precision > ft_ulltoa_base_size(x, 2))
		leading_zeros = spec->precision - ft_ulltoa_base_size(x, 2) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(x, 2) + leading_zeros + 2 *
			spec->flags.flags_sharp * (x != 0));
	str[ft_ulltoa_base_size(x, 2) + leading_zeros + 2 * spec->flags.flags_sharp
	* (x != 0) - 1] = '\0';
	if (spec->flags.flags_sharp && x)
		ft_strcat(str, "0b");
	ft_strfilln(str + spec->flags.flags_sharp * 2, '0', leading_zeros);
	ft_ulltoa_base(str + leading_zeros + 2 * spec->flags.flags_sharp * (x != 0),
			x, "01");
	if (ft_isupper(spec->cast[0]))
		ft_striter(str, printf_toupper);
	bytes_printed += printf_write_width(spec, str, (spec->precision ||
	!spec->precision_activated) ? ft_strlen(str) : 0, ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_b(va_list *params, struct s_printf_specificator *spec)
{
	unsigned int	x;
	int				bytes_printed;
	int				leading_zeros;
	char			*str;

	bytes_printed = 0;
	x = va_arg(*params, int);
	leading_zeros = printf_bx_leading_zeros(spec, x, 2);
	if (spec->precision > ft_ulltoa_base_size(x, 2))
		leading_zeros = spec->precision - ft_ulltoa_base_size(x, 2) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(x, 2) + leading_zeros + 2 *
			spec->flags.flags_sharp * (x != 0));
	str[ft_ulltoa_base_size(x, 2) + leading_zeros + 2 * spec->flags.flags_sharp
	* (x != 0) - 1] = '\0';
	if (spec->flags.flags_sharp && x)
		ft_strcat(str, "0b");
	ft_strfilln(str + spec->flags.flags_sharp * 2, '0', leading_zeros);
	ft_ulltoa_base(str + leading_zeros + 2 * spec->flags.flags_sharp * (x != 0),
			x, "01");
	if (ft_isupper(spec->cast[0]))
		ft_striter(str, printf_toupper);
	bytes_printed += printf_write_width(spec, str, (spec->precision ||
	!spec->precision_activated) ? ft_strlen(str) : 0, ' ');
	free(str);
	return (bytes_printed);
}
