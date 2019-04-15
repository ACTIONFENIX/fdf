/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:00:57 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/08 19:23:57 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int val, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		if (((unsigned char*)ptr)[i] == (unsigned char)val)
			return ((void*)(ptr + i));
		++i;
	}
	return (0);
}
