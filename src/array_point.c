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

void	array_point_init(struct s_array_point *sarr) //inline
{
	array_init(&sarr->arr, sizeof(struct s_point), 0, 0);
}

void	array_point_destroy(struct s_array_point *sarr) //inline
{
	array_destroy(&sarr->arr);
}

size_t	array_point_size(const struct s_array_point *sarr) //inline
{
	return (array_size(&sarr->arr));
}

struct s_point array_point_at(struct s_array_point *sarr, size_t i) //inline
{
	return (*(struct s_point*)array_at(&sarr->arr, i));
}

struct s_point *array_point_pat(struct s_array_point *sarr, size_t i)
{
	return ((struct s_point*)array_at(&sarr->arr, i));
}

bool	array_point_push_back(struct s_array_point *sarr, const struct s_point *p) //inline
{
	return (array_push_back(&sarr->arr, p));
}

struct s_point array_point_front(struct s_array_point *sarr)
{
	return array_point_at(sarr, 0);
}

struct s_point array_point_back(struct s_array_point *sarr)
{
	return array_point_at(sarr, array_point_size(sarr) - 1);
}
