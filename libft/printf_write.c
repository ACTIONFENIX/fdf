/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:12:19 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:12:21 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_print_raw_string(const char **ptr, int fd)
{
	int			bytes_printed;
	const char	*find_specificator;

	bytes_printed = 0;
	find_specificator = ft_strchr(*ptr, '%');
	if (!find_specificator)
		find_specificator = *ptr + ft_strlen(*ptr);
	bytes_printed += write(fd, *ptr, find_specificator - *ptr);
	*ptr = find_specificator;
	return (bytes_printed);
}

int	printf_write_width(struct s_printf_specificator *spec, const char *str,
		int n, char delim)
{
	int delim_size;
	int bytes_printed;

	bytes_printed = 0;
	delim_size = ft_max(spec->width, n) - n;
	if (spec->flags.flags_minus == 0)
	{
		while (delim_size)
		{
			bytes_printed += write(spec->fd, &delim, 1);
			--delim_size;
		}
	}
	bytes_printed += write(spec->fd, str, n);
	while (delim_size)
	{
		bytes_printed += write(spec->fd, &delim, 1);
		--delim_size;
	}
	return (bytes_printed);
}

int	printf_write_with_specificator(va_list *params,
		struct s_printf_specificator *spec)
{
	size_t i;

	i = 0;
	while (i < sizeof(g_cast_func) / sizeof(g_cast_func[0]))
	{
		if (ft_strcmp(spec->cast, g_cast_func[i].code) == 0)
			break ;
		++i;
	}
	if (i != sizeof(g_cast_func) / sizeof(g_cast_func[0]))
	{
		return (g_cast_func[i].func(params, spec));
	}
	else
	{
		if (spec->cast[1])
		{
			return (printf_cast_default(params, spec));
		}
		else
		{
			return (0);
		}
	}
}
