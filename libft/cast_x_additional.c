/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_x_additional.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:22:33 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/31 12:22:34 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_bx_leading_zeros(struct s_printf_specificator *spec,
		unsigned long long int x, int base)
{
	int leading_zeros;

	leading_zeros = (ft_max(spec->width, ft_ulltoa_base_size(x, base) + 2 *
	spec->flags.flags_sharp * (x != 0) - 1) - ft_ulltoa_base_size(x, base) - 2 *
			spec->flags.flags_sharp + 1) * spec->flags.flags_zero;
	return (leading_zeros);
}
