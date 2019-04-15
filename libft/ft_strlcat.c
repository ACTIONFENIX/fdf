/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:56:52 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/08 16:05:53 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	dest += dest_len;
	if (size < dest_len)
		return (ft_strlen(src) + size);
	while (i < size - dest_len && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	if (!src[i])
		dest[i] = '\0';
	if (i && i == size - dest_len)
		dest[i - 1] = '\0';
	return (dest_len + ft_strlen(src));
}
