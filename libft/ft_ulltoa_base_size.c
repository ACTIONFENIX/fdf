/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:28:54 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/25 14:28:56 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ulltoa_base_size(unsigned long long int val, int base)
{
	int size;

	size = 0;
	if (!val)
		++size;
	while (val)
	{
		val /= base;
		++size;
	}
	return (size + 1);
}
