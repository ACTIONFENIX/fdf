/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:57:48 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/07 20:03:31 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	size_t i;
	size_t j;
	size_t sublen;

	i = 0;
	sublen = ft_strlen(substr);
	if (!str[i] && !substr[i])
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		while (substr[j] && str[i + j] == substr[j])
		{
			++j;
		}
		if (j == sublen)
			return ((char*)(str + i));
		++i;
	}
	return (0);
}
