/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:30:24 by myaremen          #+#    #+#             */
/*   Updated: 2019/03/29 14:30:25 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_point.h"
#include "array2_point.h"

void	array2_point_init(struct s_array2_point *sarr) //inline
{
	array_init(&sarr->arr, sizeof(struct s_array_point), 0, 0);
}

void	array2_point_destroy(struct s_array2_point *sarr) //inline
{
	array_destroy(&sarr->arr);
}

size_t	array2_point_size(const struct s_array2_point *sarr) //inline
{
	return (array_size(&sarr->arr));
}

struct s_array_point *array2_point_at(struct s_array2_point *sarr, size_t i) //inline
{
	return (array_at(&sarr->arr, i));
}

bool	array2_point_push_back(struct s_array2_point *sarr, const struct s_array_point *p) //inline
{
	return (array_push_back(&sarr->arr, p));
}

struct s_array_point *array2_point_front(struct s_array2_point *sarr)
{
	return array2_point_at(sarr, 0);
}

struct s_array_point *array2_point_back(struct s_array2_point *sarr)
{
	return array2_point_at(sarr, array2_point_size(sarr) - 1);
}
