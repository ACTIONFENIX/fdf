/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:59:12 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/08 19:30:12 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		((unsigned char*)ptr)[i] = (unsigned char)val;
		++i;
	}
	return (ptr);
}
