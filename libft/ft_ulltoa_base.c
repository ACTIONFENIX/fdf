/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:14:32 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/25 14:14:34 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ulltoa_base(char *str, unsigned long long int val, const char *abase)
{
	int str_size;
	int base;
	int i;

	base = ft_strlen(abase);
	str_size = ft_ulltoa_base_size(val, base);
	if (val == 0)
		str[0] = '0';
	i = str_size - 2;
	str[str_size - 1] = '\0';
	while (val)
	{
		str[i] = abase[val % base];
		val /= base;
		--i;
	}
}
