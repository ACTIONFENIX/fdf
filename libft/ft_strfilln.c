/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfilln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:53:02 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/30 19:51:24 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strfilln(char *str, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		str[i] = c;
		++i;
	}
}
