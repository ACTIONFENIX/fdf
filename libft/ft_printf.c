/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:11:21 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:11:22 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char g_printf_modifiers[5][3] = { "hh", "h", "ll", "l", "L" };

struct s_cast g_cast_func[13] = {
	{"d", printf_cast_d},
	{"i", printf_cast_d},
	{"o", printf_cast_o},
	{"u", printf_cast_u},
	{"x", printf_cast_x},
	{"X", printf_cast_x},
	{"c", printf_cast_c},
	{"s", printf_cast_s},
	{"p", printf_cast_p},
	{"f", printf_cast_f},
	{"F", printf_cast_f},
	{"%", printf_cast_pr},
	{"b", printf_cast_b}
};

int	printf_core(int fd, const char *format, va_list *params)
{
	int								bytes_printed;
	struct s_printf_specificator	specificator;
	const char						*ptr;

	bytes_printed = 0;
	ptr = format;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			++ptr;
			ptr = printf_parse_specificator(params, ptr, &specificator);
			specificator.fd = fd;
			bytes_printed += printf_write_with_specificator(params,
					&specificator);
		}
		else
		{
			bytes_printed += printf_print_raw_string(&ptr, fd);
		}
	}
	return (bytes_printed);
}

int	ft_printf(const char *format, ...)
{
	int		ret_val;
	va_list	params;

	va_start(params, format);
	ret_val = printf_core(1, format, &params);
	va_end(params);
	return (ret_val);
}

int	fd_printf(int fd, const char *format, ...)
{
	int		ret_val;
	va_list	params;

	va_start(params, format);
	ret_val = printf_core(fd, format, &params);
	va_end(params);
	return (ret_val);
}
