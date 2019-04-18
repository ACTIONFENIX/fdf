/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:50:27 by myaremen          #+#    #+#             */
/*   Updated: 2019/03/28 18:50:29 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "point.h"
#include "array_point.h"
#include "array2_point.h"
#include "matrix4.h"
#include "color.h"
#include "options.h"
#include "data.h"
#include "keyboard.h"
#include "draw.h"
#include "parse.h"

int main(int argc, char *argv[])
{
	struct s_data data;

	get_data(&data);
	if (argc != 2)
	{
		ft_printf("usage: ./fdf filename\n");
		return (1);
	}
	data.draw_context.mlx_ptr = mlx_init();
	if (!data.draw_context.mlx_ptr)
	{
		ft_printf("Error: Failed to set up the connection to X server.\n");
		exit(1);
	}
	data.draw_context.window_x = 1280;
	data.draw_context.window_y = 720;
	data.draw_context.win_ptr = mlx_new_window(data.draw_context.mlx_ptr, data.draw_context.window_x, data.draw_context.window_y, "Fdf");
	if (!data.draw_context.win_ptr)
	{
		ft_printf("Error: Failed to create window.\n");
		exit(1);
	}
	data.fps = 0;
	data.draw_context.pixel_put = &pixel_put_image;
	create_image(&data.draw_context);
	init_options(&data.options);

	array2_point_init(&data.points);
	if (!read_points(&data.points, argv[1]))
	{
		array2_point_destroy(&data.points);
		ft_printf("error\n");
		return (1);
	}
	identity_matrix4(&data.basic);
	center_surface(&data);
	redraw_scene(&data);

	mlx_hook(data.draw_context.win_ptr, 2, 0, &key_hook, &data);
	mlx_loop(data.draw_context.mlx_ptr);
	array2_point_destroy(&data.points);
	return 0;
}
