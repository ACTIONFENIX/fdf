/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specificator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:12:05 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:12:07 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printf_parse_flags_specificator(const char *format,
		const char *format_end, struct s_printf_specificator *spec)
{
	const char *i;

	i = format;
	while (i != format_end)
	{
		if (*i == '-')
			spec->flags.flags_minus = 1;
		else if (*i == '+')
			spec->flags.flags_plus = 1;
		else if (*i == ' ')
			spec->flags.flags_space = 1;
		else if (*i == '#')
			spec->flags.flags_sharp = 1;
		else if (*i == '0' && !ft_isdigit(i[-1]) && i[-1] != '.' && i[1] != '.')
			spec->flags.flags_zero = 1;
		++i;
	}
}

void	printf_parse_width_specificator(va_list *params, const char *format,
		const char *format_end, struct s_printf_specificator *spec)
{
	const char *i;

	i = format;
	while (i != format_end)
	{
		if (i[-1] != '.' && ft_atoi(i))
			spec->width = ft_atoi(i);
		if (i[-1] != '.' || ft_atoi(i))
		{
			while (i != format_end && ft_isdigit(*i))
				++i;
		}
		if (i != format_end)
			++i;
		if (i[-1] == '*' && i[-2] != '.')
		{
			spec->width = va_arg(*params, int);
			if (spec->width < 0)
			{
				spec->width = -spec->width;
				spec->flags.flags_minus = 1;
			}
		}
	}
}

void	printf_parse_precision_specificator(va_list *params, const char *format,
		const char *format_end, struct s_printf_specificator *spec)
{
	const char *i;

	i = format_end;
	while (i != format && *i != '.')
	{
		--i;
	}
	if (i[0] == '.')
		spec->precision_activated = 1;
	if (i != format_end)
		++i;
	if (i[-1] == '.')
		spec->precision = ft_atoi(i);
	if (i[-1] == '.' && i[0] == '*')
	{
		spec->precision = va_arg(*params, int);
		spec->precision_activated = 1;
		if (spec->precision < 0)
		{
			spec->precision = 0;
			spec->precision_activated = 0;
		}
	}
}

void	printf_parse_modifier_specificator(const char *format,
		const char *format_end, struct s_printf_specificator *spec)
{
	size_t i;
	size_t saved_i;

	saved_i = sizeof(g_printf_modifiers) / sizeof(g_printf_modifiers[0]);
	while (format != format_end)
	{
		i = 0;
		while (i < sizeof(g_printf_modifiers) / sizeof(g_printf_modifiers[0]))
		{
			if (ft_strncmp(format, g_printf_modifiers[i],
					ft_strlen(g_printf_modifiers[i])) == 0)
				break ;
			++i;
		}
		if (i == sizeof(g_printf_modifiers) / sizeof(g_printf_modifiers[0]))
			++format;
		else if (ft_strncmp(format, g_printf_modifiers[i],
				ft_strlen(g_printf_modifiers[i])) == 0)
		{
			saved_i = i;
			format += ft_strlen(g_printf_modifiers[i]);
		}
	}
	if (saved_i != sizeof(g_printf_modifiers) / sizeof(g_printf_modifiers[0]))
		ft_strcpy(spec->modifier, g_printf_modifiers[saved_i]);
}

void	printf_parse_cast_specificator(const char *format,
		const char *format_end, struct s_printf_specificator *spec)
{
	size_t i;

	i = 0;
	while (format <= format_end &&
	(i == sizeof(g_cast_func) / sizeof(g_cast_func[0]) ||
	ft_strncmp(format, g_cast_func[i].code,
			ft_strlen(g_cast_func[i].code)) != 0))
	{
		i = 0;
		while (i < sizeof(g_cast_func) / sizeof(g_cast_func[0]))
		{
			if (ft_strncmp(format, g_cast_func[i].code,
					ft_strlen(g_cast_func[i].code)) == 0)
				break ;
			++i;
		}
		if (i == sizeof(g_cast_func) / sizeof(g_cast_func[0]))
			++format;
	}
	if (i != sizeof(g_cast_func) / sizeof(g_cast_func[0]))
		ft_strcpy(spec->cast, g_cast_func[i].code);
	else
		ft_strncpy(spec->cast + 1, format_end, 1);
}
