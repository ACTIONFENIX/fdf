/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:58:11 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/07 20:03:57 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t i;
	size_t j;
	size_t sublen;

	i = 0;
	sublen = ft_strlen(substr);
	while (i < len && str[i])
	{
		j = 0;
		while (i + j < len && substr[j] && str[i + j] == substr[j])
		{
			++j;
		}
		if (j == sublen)
			return ((char*)(str + i));
		++i;
	}
	return (0);
}
