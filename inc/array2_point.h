/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2_point.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:25:32 by myaremen          #+#    #+#             */
/*   Updated: 2019/03/29 14:25:34 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY2_POINT_H
# define ARRAY2_POINT_H

#include "libft.h"

struct s_array2_point
{
	struct s_array arr;
};

void	array2_point_init(struct s_array2_point *sarr);

void	array2_point_destroy(struct s_array2_point *sarr);

size_t	array2_point_size(const struct s_array2_point *sarr);

struct s_array_point *array2_point_at(struct s_array2_point *sarr, size_t i);

bool	array2_point_push_back(struct s_array2_point *sarr, const struct s_array_point *p);

struct s_array_point *array2_point_front(struct s_array2_point *sarr);

struct s_array_point *array2_point_back(struct s_array2_point *sarr);

#endif