/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:57:28 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/08 19:25:08 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if ((unsigned char)str[len] == (unsigned char)c)
			return ((char*)(str + len));
		--len;
	}
	if ((unsigned char)str[len] == (unsigned char)c)
		return ((char*)(str + len));
	return (0);
}
