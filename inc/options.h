/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:47:00 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 16:47:01 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include "matrix4.h"
# include "array2_point.h"
# include "draw_context.h"

# define TARGET_IMAGE 0
# define TARGET_SCREEN 1

struct s_options
{
	int show_help;
	int diagonal_lines;
	int cut_line_window_border;
	int show_framerate;
	int target;
	float zscale;
};

void init_options(struct s_options *options);

void handle_options(int key, struct s_options *options, struct s_draw_context *draw_context);

#endif
