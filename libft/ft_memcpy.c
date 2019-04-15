/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:59:48 by myaremen          #+#    #+#             */
/*   Updated: 2018/10/30 19:18:21 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		++i;
	}
	return (dest);
}
