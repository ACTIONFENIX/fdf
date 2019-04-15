/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_douxb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:13:27 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:13:28 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_cast_d(va_list *params, struct s_printf_specificator *spec)
{
	if (spec->flags.flags_zero && (spec->precision || spec->flags.flags_minus))
		spec->flags.flags_zero = 0;
	if (spec->flags.flags_space && spec->flags.flags_plus)
		spec->flags.flags_space = 0;
	if (ft_strcmp(spec->modifier, "hh") == 0)
		return (printf_write_hhd(params, spec));
	else if (ft_strcmp(spec->modifier, "h") == 0)
		return (printf_write_hd(params, spec));
	else if (ft_strcmp(spec->modifier, "l") == 0)
		return (printf_write_ld(params, spec));
	else if (ft_strcmp(spec->modifier, "ll") == 0)
		return (printf_write_lld(params, spec));
	else
		return (printf_write_d(params, spec));
}

int	printf_cast_o(va_list *params, struct s_printf_specificator *spec)
{
	if (spec->flags.flags_zero && (spec->precision || spec->flags.flags_minus))
		spec->flags.flags_zero = 0;
	if (ft_strcmp(spec->modifier, "hh") == 0)
		return (printf_write_hho(params, spec));
	else if (ft_strcmp(spec->modifier, "h") == 0)
		return (printf_write_ho(params, spec));
	else if (ft_strcmp(spec->modifier, "l") == 0)
		return (printf_write_lo(params, spec));
	else if (ft_strcmp(spec->modifier, "ll") == 0)
		return (printf_write_llo(params, spec));
	else
		return (printf_write_o(params, spec));
}

int	printf_cast_u(va_list *params, struct s_printf_specificator *spec)
{
	if (spec->flags.flags_zero && (spec->precision || spec->flags.flags_minus))
		spec->flags.flags_zero = 0;
	if (ft_strcmp(spec->modifier, "hh") == 0)
		return (printf_write_hhu(params, spec));
	else if (ft_strcmp(spec->modifier, "h") == 0)
		return (printf_write_hu(params, spec));
	else if (ft_strcmp(spec->modifier, "l") == 0)
		return (printf_write_lu(params, spec));
	else if (ft_strcmp(spec->modifier, "ll") == 0)
		return (printf_write_llu(params, spec));
	else
		return (printf_write_u(params, spec));
}

int	printf_cast_x(va_list *params, struct s_printf_specificator *spec)
{
	if (spec->flags.flags_zero && (spec->precision || spec->flags.flags_minus))
		spec->flags.flags_zero = 0;
	if (ft_strcmp(spec->modifier, "hh") == 0)
		return (printf_write_hhx(params, spec));
	else if (ft_strcmp(spec->modifier, "h") == 0)
		return (printf_write_hx(params, spec));
	else if (ft_strcmp(spec->modifier, "l") == 0)
		return (printf_write_lx(params, spec));
	else if (ft_strcmp(spec->modifier, "ll") == 0)
		return (printf_write_llx(params, spec));
	else
		return (printf_write_x(params, spec));
}

int	printf_cast_b(va_list *params, struct s_printf_specificator *spec)
{
	if (spec->flags.flags_zero && (spec->precision || spec->flags.flags_minus))
		spec->flags.flags_zero = 0;
	if (ft_strcmp(spec->modifier, "hh") == 0)
		return (printf_write_hhb(params, spec));
	else if (ft_strcmp(spec->modifier, "h") == 0)
		return (printf_write_hb(params, spec));
	else if (ft_strcmp(spec->modifier, "l") == 0)
		return (printf_write_lb(params, spec));
	else if (ft_strcmp(spec->modifier, "ll") == 0)
		return (printf_write_llb(params, spec));
	else
		return (printf_write_b(params, spec));
}
