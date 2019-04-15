/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:03:00 by myaremen          #+#    #+#             */
/*   Updated: 2019/02/21 16:03:02 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	dup = malloc(sizeof(char) * (n + 1));
	if (dup)
	{
		ft_strncpy(dup, str, n);
		dup[n] = '\0';
	}
	return (dup);
}
