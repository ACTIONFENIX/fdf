/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:29:25 by myaremen          #+#    #+#             */
/*   Updated: 2019/03/29 14:29:26 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_POINT_H
# define FDF_POINT_H

#include "color.h"
#include "matrix4.h"

struct s_point
{
	int x;
	int y;
	int z;
	union u_color color;
};

struct s_point make_point(int x, int y, int z, unsigned int color);

void point_swap(struct s_point *l, struct s_point *r);

void point_multiply_matrix4(struct s_point *point, const struct s_matrix4 *m);

#endif
