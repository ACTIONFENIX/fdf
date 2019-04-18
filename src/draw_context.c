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

void create_image(struct s_draw_context *draw_context)
{
	draw_context->image.img_ptr = mlx_new_image(draw_context->mlx_ptr, draw_context->window_x, draw_context->window_y);
	draw_context->image.image = mlx_get_data_addr(draw_context->image.img_ptr, &draw_context->image.bits_per_pixel, &draw_context->image.size_line, &draw_context->image.endian);
}
