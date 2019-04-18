/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2_point_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:27:29 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 18:27:30 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array2_point.h"

struct s_array_point *array2_point_at(struct s_array2_point *sarr, size_t i)
{
	return (array_at(&sarr->arr, i));
}

struct s_array_point *array2_point_front(struct s_array2_point *sarr)
{
	return array2_point_at(sarr, 0);
}

struct s_array_point *array2_point_back(struct s_array2_point *sarr)
{
	return array2_point_at(sarr, array2_point_size(sarr) - 1);
}
