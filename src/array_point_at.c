/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_point_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:27:41 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 18:27:42 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_point.h"
#include "point.h"

struct s_point array_point_at(struct s_array_point *sarr, size_t i)
{
	return (*(struct s_point*)array_at(&sarr->arr, i));
}

struct s_point *array_point_pat(struct s_array_point *sarr, size_t i)
{
	return ((struct s_point*)array_at(&sarr->arr, i));
}

struct s_point array_point_front(struct s_array_point *sarr)
{
	return array_point_at(sarr, 0);
}

struct s_point array_point_back(struct s_array_point *sarr)
{
	return array_point_at(sarr, array_point_size(sarr) - 1);
}
