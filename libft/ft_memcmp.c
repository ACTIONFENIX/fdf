/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:01:52 by myaremen          #+#    #+#             */
/*   Updated: 2018/10/30 19:26:03 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		if (((unsigned char*)ptr1)[i] != ((unsigned char*)ptr2)[i])
			return (((unsigned char*)ptr1)[i] - ((unsigned char*)ptr2)[i]);
		++i;
	}
	return (0);
}
