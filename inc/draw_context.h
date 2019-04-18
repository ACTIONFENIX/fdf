/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_context.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:24:06 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 17:24:07 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_CONTEXT_H
# define DRAW_CONTEXT_H

# include "draw_context.h"

struct	s_image
{
	void	*img_ptr;
	char	*image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

struct	s_draw_context
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				window_x;
	int				window_y;
	struct s_image	image;
	int				(*pixel_put)(void*, void*, int, int, int);
};

void	create_image(struct s_draw_context *draw_context);

int		pixel_put_image(void *mlx_ptr, void *win_ptr, int x, int y, int color);

#endif
