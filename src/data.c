/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:56:40 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 16:56:41 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mlx.h"
#include "parse.h"

struct s_data	*get_data(struct s_data *set_data)
{
	static struct s_data *save_data = 0;

	if (save_data == 0)
	{
		save_data = set_data;
	}
	return (save_data);
}

bool			init_data(struct s_data *data, const char *filename)
{
	data->draw_context.mlx_ptr = mlx_init();
	if (!data->draw_context.mlx_ptr)
		return (0);
	data->draw_context.window_x = 1280;
	data->draw_context.window_y = 720;
	data->draw_context.win_ptr = mlx_new_window(data->draw_context.mlx_ptr,
			data->draw_context.window_x, data->draw_context.window_y, "Fdf");
	if (!data->draw_context.win_ptr)
		return (0);
	data->fps = 0;
	data->draw_context.pixel_put = &pixel_put_image;
	create_image(&data->draw_context);
	init_options(&data->options);
	array2_point_init(&data->points);
	if (!read_points(&data->points, filename))
		return (0);
	identity_matrix4(&data->basic);
	return (1);
}
