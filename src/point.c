/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:58:19 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 15:58:21 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

struct s_point	make_point(int x, int y, int z, unsigned int color)
{
	struct s_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color.color = color;
	return (point);
}

void			point_swap(struct s_point *l, struct s_point *r)
{
	struct s_point tmp;

	tmp = *l;
	*l = *r;
	*r = tmp;
}

void			point_multiply_matrix4(struct s_point *point,
		const struct s_matrix4 *m)
{
	struct s_point new_point;

	new_point.x = point->x * m->arr[0][0] + point->y * m->arr[1][0] +
			point->z * m->arr[2][0] + m->arr[3][0];
	new_point.y = point->x * m->arr[0][1] + point->y * m->arr[1][1] +
			point->z * m->arr[2][1] + m->arr[3][1];
	new_point.z = point->x * m->arr[0][2] + point->y * m->arr[1][2] +
			point->z * m->arr[2][2] + m->arr[3][2];
	new_point.color = point->color;
	*point = new_point;
}
