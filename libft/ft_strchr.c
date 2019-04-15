/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:57:06 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/08 19:24:38 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((unsigned char)(*str) == (unsigned char)c)
			return ((char*)str);
		++str;
	}
	if ((unsigned char)(*str) == (unsigned char)c)
		return ((char*)str);
	return (0);
}
