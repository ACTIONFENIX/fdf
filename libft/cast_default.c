/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:46:14 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/25 12:46:15 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_cast_default(va_list *params, struct s_printf_specificator *spec)
{
	char	c;
	int		bytes_printed;

	(void)params;
	bytes_printed = 0;
	c = spec->cast[1];
	bytes_printed += printf_write_width(spec, &c, 1, ' ');
	return (bytes_printed);
}
