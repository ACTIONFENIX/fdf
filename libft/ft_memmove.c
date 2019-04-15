/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:00:25 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/08 19:32:37 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	void *buf;

	buf = malloc(sizeof(unsigned char) * num);
	if (buf)
	{
		ft_memcpy(buf, src, num);
		ft_memcpy(dest, buf, num);
		free(buf);
	}
	return (dest);
}
