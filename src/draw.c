#include "draw.h"
#include "mlx.h"
#include "array2_point.h"
#include "array_point.h"
#include "point.h"
#include <time.h>

void	draw_line(struct s_draw_context *draw_context, struct s_options *options, struct s_point start, struct s_point end)
{
	int length_x;
	int length_y;
	int dx;
	int dy;
	int i;
	int error;

	if (start.x > end.x)
	{
		point_swap(&start, &end);
	}
	length_x = abs(end.x - start.x);
	length_y = abs(end.y - start.y);
	dx = ft_sign(end.x - start.x);
	dy = ft_sign(end.y - start.y);
	error = 0;
	i = 0;
	if (length_x >= length_y)
	{
		while (start.x != end.x)
		{
			if (!(options->cut_line_window_border && (start.x < 0 || start.x > draw_context->window_x)))
			{
				draw_context->pixel_put(draw_context->mlx_ptr, draw_context->win_ptr, start.x, start.y, average_color(start.color.color, end.color.color, i, length_x));
			}
			start.x += dx;
			error += length_y;
			if (2 * error >= length_x)
			{
				start.y += dy;
				error -= length_x;
			}
			++i;
		}
	}
	else
	{
		while (start.y != end.y)
		{
			if (!(options->cut_line_window_border && (start.y < 0 || start.y > draw_context->window_y)))
			{
				draw_context->pixel_put(draw_context->mlx_ptr, draw_context->win_ptr, start.x, start.y, average_color(start.color.color, end.color.color, i, length_y));
			}
			start.y += dy;
			error += length_x;
			if (2 * error >= length_y)
			{
				start.x += dx;
				error -= length_y;
			}
			++i;
		}
	}
}

void draw_points(struct s_data *data, struct s_array2_point *points, const struct s_matrix4 *basic)
{
	size_t i;
	size_t j;
	struct s_array_point *arr;
	struct s_point line_start;
	struct s_point line_end;

	i = 0;
	while (i < array2_point_size(points))
	{
		arr = array2_point_at(points, i);
		j = 0;
		while (j < array_point_size(arr))
		{
			arr = array2_point_at(points, i);

			if (j + 1 != array_point_size(arr))
			{
				line_start = array_point_at(arr, j);
				line_start.z *= data->options.zscale;
				point_multiply_matrix4(&line_start, basic);
				line_end = array_point_at(arr, j + 1);
				line_end.z *= data->options.zscale;
				point_multiply_matrix4(&line_end, basic);
				line_start.x = line_start.x + data->xcamera;
				line_start.y = line_start.y + data->ycamera;
				line_end.x =  line_end.x + data->xcamera;
				line_end.y = line_end.y + data->ycamera;
				draw_line(&data->draw_context, &data->options, line_start, line_end);
			}

			if (i + 1 != array2_point_size(points))
			{
				line_start = array_point_at(arr, j);
				line_start.z *= data->options.zscale;
				point_multiply_matrix4(&line_start, basic);
				line_end = array_point_at(array2_point_at(points, i + 1), j);
				line_end.z *= data->options.zscale;
				point_multiply_matrix4(&line_end, basic);
				line_start.x = line_start.x + data->xcamera;
				line_start.y = line_start.y + data->ycamera;
				line_end.x = line_end.x + data->xcamera;
				line_end.y = line_end.y + data->ycamera;
				draw_line(&data->draw_context, &data->options, line_start, line_end);
			}

			if (data->options.diagonal_lines)
			{
				if (j + 1 != array_point_size(arr) && i + 1 != array2_point_size(points))
				{
					line_start = array_point_at(arr, j);
					line_start.z *= data->options.zscale;
					point_multiply_matrix4(&line_start, basic);
					arr = array2_point_at(points, i + 1);
					line_end = array_point_at(arr, j + 1);
					line_end.z *= data->options.zscale;
					point_multiply_matrix4(&line_end, basic);
					line_start.x = line_start.x + data->xcamera;
					line_start.y = line_start.y + data->ycamera;
					line_end.x =  line_end.x + data->xcamera;
					line_end.y = line_end.y + data->ycamera;
					draw_line(&data->draw_context, &data->options, line_start, line_end);
				}
			}
			++j;
		}
		++i;
	}
}

void draw_fps(struct s_draw_context *draw_context, struct s_data *data)
{
	char *fps;

	fps = ft_itoa(data->fps);
	mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, draw_context->window_x - 50, 25, YELLOW, fps);
	free(fps);
}

void draw_help(struct s_draw_context *draw_context, struct s_data *data)
{
	mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 25, GREEN, "Controls:");
	mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 45, GREEN, "H - show Help");
	mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 65, GREEN, "WASD - move object");
	mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 85, GREEN, "R - reset view");
	mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 105, GREEN, "[arrows, Q, E] - rotate");
	if (data->options.diagonal_lines == 0)
	{
		mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 125, GREEN, "V - add Diagonal lines");
	}
	else
	{
		mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 125, GREEN, "V - remove Diagonal lines");
	}
	if (data->options.cut_line_window_border == 0)
	{
		mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 145, GREEN, "O - cut lines out of window");
	}
	else
	{
		mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 145, GREEN, "O - don't cut lines out of window");
	}
	if (data->options.show_framerate == 1)
	{
		mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 165, GREEN, "F - hide FPS");
		draw_fps(draw_context, data);
	}
	else
	{
		mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 165, GREEN, "F - show FPS");
	}
	if (data->options.target == TARGET_SCREEN)
	{
		mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 185, GREEN, "J - draw to image");
	}
	else
	{
		mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 185, GREEN, "J - draw to screen");
	}
	mlx_string_put(draw_context->mlx_ptr, draw_context->win_ptr, 25, 205, GREEN, "[*/] - scale z");
}

void redraw_scene(struct s_data *data)
{
	clock_t start;

	start = clock();
	if (data->options.target == TARGET_IMAGE)
	{
		ft_memset(data->draw_context.image.image, 0, data->draw_context.window_y * data->draw_context.window_x * 4);
	}
	mlx_clear_window(data->draw_context.mlx_ptr, data->draw_context.win_ptr);
	draw_points(data, &data->points, &data->basic);
	if (data->options.target == TARGET_IMAGE)
	{
		mlx_put_image_to_window(data->draw_context.mlx_ptr, data->draw_context.win_ptr, data->draw_context.image.img_ptr, 0, 0);
	}
	if (data->options.show_help)
	{
		draw_help(&data->draw_context, data);
	}
	data->fps = CLOCKS_PER_SEC / (clock() - start);
}
