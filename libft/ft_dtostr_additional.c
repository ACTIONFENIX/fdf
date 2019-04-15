/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtostr_additional.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:04:45 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:04:47 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtostr_isnan_or_inf(double d)
{
	char *str;

	if (ft_isnan(d))
	{
		str = (char*)malloc(4);
		ft_strcpy(str, "nan");
		return (str);
	}
	if (ft_isinf(d))
	{
		str = (char*)malloc(4 + ft_double_is_negative(d));
		if (ft_double_is_negative(d))
			ft_strcat(str, "-");
		ft_strcat(str, "inf");
		return (str);
	}
	return (0);
}
