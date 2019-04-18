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

#include "data.h"
#include "draw.h"
#include "keyboard.h"
#include "mlx.h"

int	main(int argc, char *argv[])
{
	struct s_data data;

	get_data(&data);
	if (argc != 2)
	{
		ft_printf("usage: ./fdf filename\n");
		return (1);
	}
	if (!init_data(&data, argv[1]))
	{
		ft_printf("error\n");
		return (1);
	}
	center_surface(&data);
	redraw_scene(&data);
	mlx_hook(data.draw_context.win_ptr, 2, 0, &key_hook, &data);
	mlx_loop(data.draw_context.mlx_ptr);
	return (0);
}
