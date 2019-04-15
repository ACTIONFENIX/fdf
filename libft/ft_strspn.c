/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:32:51 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/06 14:36:12 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *str, const char *substr)
{
	size_t i;

	i = 0;
	while (str[i] && substr[i])
	{
		if (!ft_strchr(substr, str[i]))
			break ;
		++i;
	}
	return (i);
}
