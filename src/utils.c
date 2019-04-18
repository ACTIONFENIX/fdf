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
