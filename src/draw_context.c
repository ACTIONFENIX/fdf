/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:00:45 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 18:00:46 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_context.h"
#include "mlx.h"
#include "data.h"

void create_image(struct s_draw_context *draw_context)
{
	draw_context->image.img_ptr = mlx_new_image(draw_context->mlx_ptr, draw_context->window_x, draw_context->window_y);
	draw_context->image.image = mlx_get_data_addr(draw_context->image.img_ptr, &draw_context->image.bits_per_pixel, &draw_context->image.size_line, &draw_context->image.endian);
}

int	pixel_put_image(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
	struct s_data *data = get_data(0);
	struct s_draw_context *draw_context = &data->draw_context;
	struct s_image *image = &draw_context->image;

	(void)mlx_ptr;
	(void)win_ptr;
	if (x >= 0 && x < draw_context->window_x && y >=0 && y >= 0 && y < draw_context->window_y)
	{
		*((int*)(&image->image[y * image->size_line + x * 4])) = color;
	}
	return (0);
}