/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:30:21 by myaremen          #+#    #+#             */
/*   Updated: 2019/03/29 14:30:22 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "array_point.h"

void	array_point_init(struct s_array_point *sarr)
{
	array_init(&sarr->arr, sizeof(struct s_point), 0, 0);
}

void	array_point_destroy(struct s_array_point *sarr)
{
	array_destroy(&sarr->arr);
}

size_t	array_point_size(const struct s_array_point *sarr)
{
	return (array_size(&sarr->arr));
}

bool	array_point_push_back(struct s_array_point *sarr, const struct s_point *p)
{
	return (array_push_back(&sarr->arr, p));
}