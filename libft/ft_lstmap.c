/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:14:20 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/08 19:31:46 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lst_pushback_static(t_list **begin, t_list *lst)
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

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	size_t	size;

	size = ft_lstsize(lst);
	if (size == 0 || !f)
		return (NULL);
	map = 0;
	while (lst)
	{
		ft_lst_pushback_static(&map, f(lst));
		lst = lst->next;
	}
	return (map);
}
