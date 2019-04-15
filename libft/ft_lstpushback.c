/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:29:57 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/06 18:36:12 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **begin, t_list *lst)
{
	t_list *iter;

	if (begin)
	{
		if (*begin)
		{
			iter = *begin;
			while (iter->next)
				iter = iter->next;
			iter->next = lst;
		}
		else
		{
			*begin = lst;
		}
	}
}
