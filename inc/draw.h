/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:54:55 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 16:54:56 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "data.h"
# include "utils.h"
# include "point.h"

void	draw_line(struct s_draw_context *draw_context,
		struct s_options *options, struct s_point start, struct s_point end);

void	draw_points(struct s_data *data, struct s_array2_point *points,
		const struct s_matrix4 *basic);

void	draw_fps(struct s_draw_context *draw_context, struct s_data *data);

void	draw_help(struct s_draw_context *draw_context, struct s_data *data);

void	redraw_scene(struct s_data *data);

#endif
