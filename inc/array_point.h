/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_point.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:25:28 by myaremen          #+#    #+#             */
/*   Updated: 2019/03/29 14:25:29 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_POINT_H
# define ARRAY_POINT_H

#include "libft.h"

struct s_array_point
{
	struct s_array arr;
};

void	array_point_init(struct s_array_point *sarr);

void	array_point_destroy(struct s_array_point *sarr);

size_t	array_point_size(const struct s_array_point *sarr);

struct s_point array_point_at(struct s_array_point *sarr, size_t i);

struct s_point *array_point_pat(struct s_array_point *sarr, size_t i);

bool	array_point_push_back(struct s_array_point *sarr, const struct s_point *p);

struct s_point array_point_front(struct s_array_point *sarr);

struct s_point array_point_back(struct s_array_point *sarr);

#endif