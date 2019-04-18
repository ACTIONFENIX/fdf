/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:48:51 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 16:48:53 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"
#include "keyboard.h"
#include "draw.h"
#include "mlx.h"

void	init_options(struct s_options *options)
{
	options->show_help = 1;
	options->diagonal_lines = 0;
	options->cut_line_window_border = 1;
	options->show_framerate = 1;
	options->target = TARGET_IMAGE;
	options->zscale = 1;
}

void	handle_options(int key, struct s_options *options,
		struct s_draw_context *draw_context)
{
	if (key == H)
		options->show_help = !options->show_help;
	else if (key == V)
		options->diagonal_lines = !options->diagonal_lines;
	else if (key == O)
		options->cut_line_window_border = !options->cut_line_window_border;
	else if (key == F)
		options->show_framerate = !options->show_framerate;
	else if (key == J)
	{
		if (options->target == TARGET_SCREEN)
		{
			options->target = TARGET_IMAGE;
			draw_context->pixel_put = &pixel_put_image;
		}
		else
		{
			options->target = TARGET_SCREEN;
			draw_context->pixel_put = &mlx_pixel_put;
		}
	}
}
