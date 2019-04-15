/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_is_negative.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:07:25 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 14:07:27 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_double_is_negative(double d)
{
	union u_dtostr_double un;

	un.d = d;
	return ((un.i & (1ULL << 63)) != 0);
}
