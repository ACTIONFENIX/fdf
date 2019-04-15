/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:11:53 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:11:54 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*printf_skip_modifier(const char *format)
{
	size_t i;

	i = 0;
	while (*format &&
	i < sizeof(g_printf_modifiers) / sizeof(g_printf_modifiers[0]))
	{
		if (ft_strncmp(format, g_printf_modifiers[i],
				ft_strlen(g_printf_modifiers[i])) == 0)
		{
			format += ft_strlen(g_printf_modifiers[i]);
			break ;
		}
		++i;
	}
	return (format);
}

const char	*printf_end_of_specificator(const char *format)
{
	size_t		i;
	const char	*format_start;

	while (*format)
	{
		format_start = format;
		format = printf_skip_modifier(format);
		if (*format && (*format == '+' || *format == '-' || *format == ' ' ||
		*format == '0' || *format == '#'))
			++format;
		if (ft_isdigit(*format) || *format == '.' || *format == '*')
			++format;
		i = 0;
		while (*format && i < sizeof(g_cast_func) / sizeof(g_cast_func[0]))
		{
			if (ft_strncmp(format, g_cast_func[i].code,
					ft_strlen(g_cast_func[i].code)) == 0)
				return (format);
			++i;
		}
		if (format_start == format)
			break ;
	}
	return (format);
}

const char	*printf_parse_specificator(va_list *params, const char *format,
		struct s_printf_specificator *spec)
{
	const char *spec_end;

	spec_end = printf_end_of_specificator(format);
	ft_memset((void *)spec, 0, sizeof(struct s_printf_specificator));
	printf_parse_flags_specificator(format, spec_end, spec);
	printf_parse_width_specificator(params, format, spec_end, spec);
	printf_parse_precision_specificator(params, format, spec_end, spec);
	if (spec->precision < 0)
	{
		spec->width = -spec->precision;
		spec->precision = 0;
	}
	printf_parse_modifier_specificator(format, spec_end, spec);
	printf_parse_cast_specificator(format, spec_end, spec);
	if (*spec_end)
		++spec_end;
	return (spec_end);
}
