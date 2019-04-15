/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:13:19 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:13:20 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_write_hhx(va_list *params, struct s_printf_specificator *spec)
{
	unsigned char	x;
	int				bytes_printed;
	int				leadzeros;
	char			*str;

	bytes_printed = 0;
	x = va_arg(*params, int);
	leadzeros = printf_bx_leading_zeros(spec, x, 16);
	if (spec->precision > ft_ulltoa_base_size(x, 16))
		leadzeros = spec->precision - ft_ulltoa_base_size(x, 16) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(x, 16) + leadzeros + 2 *
			spec->flags.flags_sharp * (x != 0));
	str[ft_ulltoa_base_size(x, 16) + leadzeros + 2 * spec->flags.flags_sharp
	* (x != 0) - 1] = '\0';
	if (spec->flags.flags_sharp && x)
		ft_strcat(str, "0x");
	ft_strfilln(str + spec->flags.flags_sharp * 2 * (x != 0), '0', leadzeros);
	ft_ulltoa_base(str + leadzeros + 2 * spec->flags.flags_sharp * (x != 0),
			x, "0123456789abcdef");
	if (ft_isupper(spec->cast[0]))
		ft_striter(str, printf_toupper);
	bytes_printed += printf_write_width(spec, str, (spec->precision || x) ?
	ft_strlen(str) : 0, ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_hx(va_list *params, struct s_printf_specificator *spec)
{
	unsigned short int	x;
	int					bytes_printed;
	int					leadzeros;
	char				*str;

	bytes_printed = 0;
	x = va_arg(*params, int);
	leadzeros = printf_bx_leading_zeros(spec, x, 16);
	if (spec->precision > ft_ulltoa_base_size(x, 16))
		leadzeros = spec->precision - ft_ulltoa_base_size(x, 16) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(x, 16) + leadzeros + 2 *
			spec->flags.flags_sharp * (x != 0));
	str[ft_ulltoa_base_size(x, 16) + leadzeros + 2 * spec->flags.flags_sharp
	* (x != 0) - 1] = '\0';
	if (spec->flags.flags_sharp && x)
		ft_strcat(str, "0x");
	ft_strfilln(str + spec->flags.flags_sharp * 2 * (x != 0), '0', leadzeros);
	ft_ulltoa_base(str + leadzeros + 2 * spec->flags.flags_sharp * (x != 0),
			x, "0123456789abcdef");
	if (ft_isupper(spec->cast[0]))
		ft_striter(str, printf_toupper);
	bytes_printed += printf_write_width(spec, str, (spec->precision || x) ?
	ft_strlen(str) : 0, ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_lx(va_list *params, struct s_printf_specificator *spec)
{
	unsigned long int	x;
	int					bytes_printed;
	int					leadzeros;
	char				*str;

	bytes_printed = 0;
	x = va_arg(*params, long int);
	leadzeros = printf_bx_leading_zeros(spec, x, 16);
	if (spec->precision > ft_ulltoa_base_size(x, 16))
		leadzeros = spec->precision - ft_ulltoa_base_size(x, 16) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(x, 16) + leadzeros + 2 *
			spec->flags.flags_sharp * (x != 0));
	str[ft_ulltoa_base_size(x, 16) + leadzeros + 2 * spec->flags.flags_sharp
	* (x != 0) - 1] = '\0';
	if (spec->flags.flags_sharp && x)
		ft_strcat(str, "0x");
	ft_strfilln(str + spec->flags.flags_sharp * 2 * (x != 0), '0', leadzeros);
	ft_ulltoa_base(str + leadzeros + 2 * spec->flags.flags_sharp * (x != 0),
			x, "0123456789abcdef");
	if (ft_isupper(spec->cast[0]))
		ft_striter(str, printf_toupper);
	bytes_printed += printf_write_width(spec, str, (spec->precision || x) ?
	ft_strlen(str) : 0, ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_llx(va_list *params, struct s_printf_specificator *spec)
{
	unsigned long long int	x;
	int						bytes_printed;
	int						leadzeros;
	char					*str;

	bytes_printed = 0;
	x = va_arg(*params, long long int);
	leadzeros = printf_bx_leading_zeros(spec, x, 16);
	if (spec->precision > ft_ulltoa_base_size(x, 16))
		leadzeros = spec->precision - ft_ulltoa_base_size(x, 16) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(x, 16) + leadzeros + 2 *
			spec->flags.flags_sharp * (x != 0));
	str[ft_ulltoa_base_size(x, 16) + leadzeros + 2 * spec->flags.flags_sharp
	* (x != 0) - 1] = '\0';
	if (spec->flags.flags_sharp && x)
		ft_strcat(str, "0x");
	ft_strfilln(str + spec->flags.flags_sharp * 2 * (x != 0), '0', leadzeros);
	ft_ulltoa_base(str + leadzeros + 2 * spec->flags.flags_sharp * (x != 0),
			x, "0123456789abcdef");
	if (ft_isupper(spec->cast[0]))
		ft_striter(str, printf_toupper);
	bytes_printed += printf_write_width(spec, str, (spec->precision || x) ?
	ft_strlen(str) : 0, ' ');
	free(str);
	return (bytes_printed);
}

int	printf_write_x(va_list *params, struct s_printf_specificator *spec)
{
	unsigned int	x;
	int				bytes_printed;
	int				leadzeros;
	char			*str;

	bytes_printed = 0;
	x = va_arg(*params, int);
	leadzeros = printf_bx_leading_zeros(spec, x, 16);
	if (spec->precision > ft_ulltoa_base_size(x, 16))
		leadzeros = spec->precision - ft_ulltoa_base_size(x, 16) + 1;
	str = (char *)malloc(ft_ulltoa_base_size(x, 16) + leadzeros + 2 *
			spec->flags.flags_sharp * (x != 0));
	str[ft_ulltoa_base_size(x, 16) + leadzeros + 2 * spec->flags.flags_sharp
	* (x != 0) - 1] = '\0';
	if (spec->flags.flags_sharp && x)
		ft_strcat(str, "0x");
	ft_strfilln(str + spec->flags.flags_sharp * 2 * (x != 0), '0', leadzeros);
	ft_ulltoa_base(str + leadzeros + 2 * spec->flags.flags_sharp * (x != 0),
			x, "0123456789abcdef");
	if (ft_isupper(spec->cast[0]))
		ft_striter(str, printf_toupper);
	bytes_printed += printf_write_width(spec, str, (spec->precision || x) ?
	ft_strlen(str) : 0, ' ');
	free(str);
	return (bytes_printed);
}
