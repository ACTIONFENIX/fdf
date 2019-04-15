/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:00:05 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/06 12:07:22 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	size_t i;

	i = 0;
	while (i < num && ((unsigned char*)src)[i] != (unsigned char)c)
		++i;
	if (i < num && (((unsigned char*)src)[i] == (unsigned char)c))
		++i;
	ft_memcpy(dest, src, i);
	if (i && ((unsigned char*)dest)[i - 1] == (unsigned char)c)
		return (dest + i);
	return (0);
}
