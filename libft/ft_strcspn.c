/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:43:20 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/01 15:48:21 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *str, const char *substr)
{
	size_t i;

	i = 0;
	while (str[i] && substr[i])
	{
		if (ft_strchr(substr, str[i]))
			break ;
		++i;
	}
	if ((!str[i] || !substr[i]) && !ft_strchr(substr, str[i]))
		++i;
	return (i);
}
