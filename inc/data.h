/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:50:25 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 16:50:27 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "options.h"
# include "draw_context.h"
# include "matrix4.h"
# include "array2_point.h"

struct s_data
{
	struct s_draw_context draw_context;
	struct s_matrix4 basic;
	struct s_array2_point points;
	int xcamera;
	int ycamera;
	struct s_options options;
	int fps;
};

struct s_data *get_data(struct s_data *set_data);

#endif
