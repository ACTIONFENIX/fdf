/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:20:53 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 18:20:54 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "color.h"
#include "mlx.h"
#include "array_point.h"
#include "point.h"

void center_surface(struct s_data *data)
{
	struct s_matrix4 m;
	int xcenter;
	int ycenter;

	identity_matrix4(&m);
	xcenter = array_point_back(array2_point_back(&data->points)).x / 2;
	ycenter = array_point_back(array2_point_back(&data->points)).y / 2;
	m.arr[3][0] =  -xcenter;
	m.arr[3][1] = -ycenter;
	data->xcamera = data->draw_context.window_x / 2;
	data->ycamera = data->draw_context.window_y / 2;
	matrix4_multiply_matrix4(&data->basic, &m);
	data->options.zscale = 1;
}

int average_color(int start, int end, int i, int imax)
{
	union u_color st;
	union u_color ed;
	float lambda = (float)i / imax;

	st.color = start;
	ed.color = end;
	st.scolor.r = (st.scolor.r + lambda * ed.scolor.r) / (1 + lambda);
	st.scolor.g = (st.scolor.g + lambda * ed.scolor.g) / (1 + lambda);
	st.scolor.b = (st.scolor.b + lambda * ed.scolor.b) / (1 + lambda);
	return st.color;
}

void free_memory(struct s_data *data)
{
	//free
	mlx_destroy_image(data->draw_context.mlx_ptr, data->draw_context.image.img_ptr);
}
