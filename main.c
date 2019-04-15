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
#include <math.h>
#include <fcntl.h>
#include "mlx.h"
#include "libft.h"
#include "point.h"
#include "array_point.h"
#include "array2_point.h"
#include "matrix4.h"
#include <time.h>

#define ESC 53
#define A 0
#define D 2
#define W 13
#define S 1
#define DOWN 125
#define UP 126
#define LEFT 123
#define RIGHT 124
#define Q 12
#define E 14
#define R 15
#define H 4
#define L 37
#define V 9
#define C 8
#define O 31
#define F 3
#define J 38
#define P 35
#define NUMPAD_PLUS 69
#define NUMPAD_MINUS 78
#define NUMPAD_ASTERISK 67
#define NUMPAD_SLASH 75

#define RED 0xff0000
#define GREEN 0x00ff00
#define BLUE 0x0000ff
#define YELLOW 0xFFFF00

#define LINE_BRESENHAM 0
#define LINE_WU 1

#define TARGET_IMAGE 0
#define TARGET_SCREEN 1

#define PROJECTION_PARALLEL 0
#define PROJECTION_CENTRAL 1

struct s_point make_point(int x, int y, int z)
{
	struct s_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

void point_swap(struct s_point *l, struct s_point *r)
{
	struct s_point tmp;

	tmp = *l;
	*l = *r;
	*r = tmp;
}

struct s_options
{
	int show_help;
	int line_method;
	int diagonal_lines;
	int cut_line_window_border;
	int show_framerate;
	int target;
	int projection_type;
};

struct s_image
{
	void *img_ptr;
	char *image;
	int bits_per_pixel;
	int size_line;
	int endian;
};

struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	int window_x;
	int window_y;
	struct s_matrix4 basic;
	struct s_array2_point points;
	int xcenter;
	int ycenter;
	struct s_options options;
	int fps;
	struct s_image image;
	int (*pixel_put)(void*, void*, int, int, int);
	void (*draw_line)(struct s_data*, struct s_point, struct s_point, int);
};

int sign(int n)
{
	if (n >= 0)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

struct s_data *get_data(struct s_data *set_data)
{
	static struct s_data *save_data = 0;

	if (save_data == 0)
	{
		save_data = set_data;
	}
	return save_data;
}

int	pixel_put_image(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
	struct s_data *data = get_data(0);
	struct s_image *image = &data->image;

	(void)mlx_ptr;
	(void)win_ptr;
	/*for (int i = 1000; i < 5000; ++i)
	{
		image->image[i] = RED;
	}*/
	if (x >= 0 && x < data->window_x && y >=0 && y >= 0 && y < data->window_y)
	{
		image->image[y * image->size_line + x * 4] = 0xffffffff;
	}
	return (0);
}

void	draw_line(struct s_data *data, struct s_point start, struct s_point end, int color) //need to be optimized
{
	float x;
	float y;
	float k;
	int delta_x;
	int delta_y;
	int step;

	if (start.x > end.x)
	{
		point_swap(&start, &end);
	}
	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	if (abs(delta_x) >= abs(delta_y))
	{
		k = (float)delta_y / delta_x;
		x = start.x;
		y = start.y;
		step = sign(delta_x);
		while (x != end.x)
		{
			if (data->options.cut_line_window_border && (x < 0 || x > data->window_x))
			{
				break;
			}
			//mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			data->pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			x += step;
			y += k;
		}
	}
	else
	{
		k = (float)delta_x / delta_y;
		if (delta_x > 0 && k < 0)
			k = -k;
		x = start.x;
		y = start.y;
		step = sign(delta_y);
		while (y != end.y)
		{
			if (data->options.cut_line_window_border && (y < 0 || y > data->window_y))
			{
				break;
			}
			//mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			data->pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			x += k;
			y += step;
		}
	}
}

void draw_line_Wu(struct s_data *data, struct s_point start, struct s_point end, int color)
{

}

void point_multiply_matrix3(struct s_point *point, const struct s_matrix4 *m)
{
	struct s_point new_point;

	new_point.x = point->x * m->arr[0][0] + point->y * m->arr[1][0] + point->z * m->arr[2][0] + m->arr[3][0];
	new_point.y = point->x * m->arr[0][1] + point->y * m->arr[1][1] + point->z * m->arr[2][1] + m->arr[3][1];
	new_point.z = point->x * m->arr[0][2] + point->y * m->arr[1][2] + point->z * m->arr[2][2] + m->arr[3][2];
	*point = new_point;
}

float matrix4_multiply_elem(const struct s_matrix4 *l, const struct s_matrix4 *r, int ci, int cj)
{
	float res;

	res = l->arr[ci][0] * r->arr[0][cj];
	res += l->arr[ci][1] * r->arr[1][cj];
	res += l->arr[ci][2] * r->arr[2][cj];
	res += l->arr[ci][3] * r->arr[3][cj];
	return (res);
}

void matrix4_multiply_matrix4(struct s_matrix4 *l, const struct s_matrix4 *r)
{
	struct s_matrix4 res;
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.arr[i][j] = matrix4_multiply_elem(l, r, i, j);
			++j;
		}
		++i;
	}
	*l = res;
}

void identity_matrix4(struct s_matrix4 *m)
{
	ft_memset(m, 0, sizeof(struct s_matrix4));
	m->arr[0][0] = 1;
	m->arr[1][1] = 1;
	m->arr[2][2] = 1;
	m->arr[3][3] = 1;
}

bool parse_line(struct s_array2_point *sarr, const char *line) //add color parsing
{
	struct s_array_point arr;
	int x;
	int z;
	static int y = 0;
	struct s_point point;
	int xstep = 20;
	int ystep = 20;

	x = 0;
	array_point_init(&arr);
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != '+' && *line != '-')
		{
			ft_printf("%s %s %d\n", line, __func__, __LINE__);
			return (0);
		}
		z = ft_atoi(line) * 5;
		line = skip_atoi_number(line);

		if (*line == ',')
		{
			++line;
			while (!ft_isspace(*line))
			{
				++line;
			}
		}

		while (ft_isspace(*line))
		{
			++line;
		}
		point = make_point(x, y, z);
		array_point_push_back(&arr, &point);
		x += xstep;
	}
	y += ystep;
	array2_point_push_back(sarr, &arr);
	return (1);
}

bool read_points(struct s_array2_point *sarr, const char *filename)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return 0;
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (!parse_line(sarr, line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	return (1);
}

void draw_points(struct s_data *data, struct s_array2_point *points, const struct s_matrix4 *basic)
{
	size_t i;
	size_t j;
	struct s_array_point *arr;
	struct s_point line_start;
	struct s_point line_end;
	struct s_point start1;
	struct s_point end1;

	i = 0;
	while (i < array2_point_size(points))
	{
		arr = array2_point_at(points, i);
		j = 0;
		while (j < array_point_size(arr))
		{
			arr = array2_point_at(points, i);
			line_start = array_point_at(arr, j);
			point_multiply_matrix3(&line_start, basic);

			if (j + 1 != array_point_size(arr))
			{
				line_end = array_point_at(arr, j + 1);
				point_multiply_matrix3(&line_end, basic);
				start1.x = line_start.x + data->window_x / 2.0;
				start1.y = line_start.y + data->window_y / 2.0;
				end1.x =  line_end.x + data->window_x / 2.0;
				end1.y = line_end.y + data->window_y / 2.0;
				data->draw_line(data, start1, end1, BLUE);
			}

			if (i + 1 != array2_point_size(points))
			{
				line_end = array_point_at(array2_point_at(points, i + 1), j);
				point_multiply_matrix3(&line_end, basic);
				start1.x = line_start.x + data->window_x / 2.0;
				start1.y = line_start.y + data->window_y / 2.0;
				end1.x = line_end.x + data->window_x / 2.0;
				end1.y = line_end.y + data->window_y / 2.0;
				data->draw_line(data, start1, end1, BLUE);
			}

			if (data->options.diagonal_lines)
			{
				if (j + 1 != array_point_size(arr) && i + 1 != array2_point_size(points))
				{
					arr = array2_point_at(points, i + 1);
					line_end = array_point_at(arr, j + 1);
					point_multiply_matrix3(&line_end, basic);
					start1.x = line_start.x + data->window_x / 2.0;
					start1.y = line_start.y + data->window_y / 2.0;
					end1.x =  line_end.x + data->window_x / 2.0;
					end1.y = line_end.y + data->window_y / 2.0;
					data->draw_line(data, start1, end1, BLUE);
				}
			}
			++j;
		}
		++i;
	}
}

void center_surface(struct s_data *data)
{
	struct s_matrix4 m;
	int xcenter;
	int ycenter;

	identity_matrix4(&m);
	xcenter = array_point_back(array2_point_back(&data->points)).x / 2;
	ycenter = array_point_back(array2_point_back(&data->points)).y / 2;
	m.arr[3][0] =  -xcenter;
	m.arr[3][1] = -ycenter;
	matrix4_multiply_matrix4(&data->basic, &m);
}

void center_scale(struct s_data *data)
{
	int xcenter;
	int ycenter;

	xcenter = array_point_at(array2_point_at(&data->points, array2_point_size(&data->points) - 1), array_point_size(array2_point_at(&data->points, array2_point_size(&data->points) - 1)) - 1).x / 2 ;
	ycenter = array_point_at(array2_point_at(&data->points, array2_point_size(&data->points) - 1), array_point_size(array2_point_at(&data->points, array2_point_size(&data->points) - 1)) - 1).y / 2;
	/*data->basic.arr[0][0] = ((float)data->window_x / 2) / xcenter;
	data->basic.arr[1][1] = ((float)data->window_y / 2) / ycenter;*/
	data->basic.arr[0][0] = 0.5;
	data->basic.arr[1][1] = 0.5;
}

void draw_fps(struct s_data *data)
{
	char *fps;

	fps = ft_itoa(data->fps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->window_x - 50, 25, YELLOW, fps);
	free(fps);
}

void draw_help(struct s_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 25, GREEN, "Controls:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 45, GREEN, "H - show Help");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 65, GREEN, "WASD - move object");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 85, GREEN, "R - reset view");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 105, GREEN, "[arrows, Q, E] - rotate");
	if (data->options.line_method == LINE_BRESENHAM)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 125, GREEN, "L - set Wu lines");
	}
	else
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 125, GREEN, "L - Bresenham lines");
	}
	if (data->options.diagonal_lines == 0)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 145, GREEN, "V - add Diagonal lines");
	}
	else
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 145, GREEN, "V - remove Diagonal lines");
	}
	if (data->options.cut_line_window_border == 0)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 165, GREEN, "O - cut lines out of window");
	}
	else
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 165, GREEN, "O - don't cut lines out of window");
	}
	if (data->options.show_framerate == 1)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 185, GREEN, "F - hide FPS");
		draw_fps(data);
	}
	else
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 185, GREEN, "F - show FPS");
	}
	if (data->options.target == TARGET_SCREEN)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 205, GREEN, "J - draw to image");
	}
	else
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 205, GREEN, "J - draw to screen");
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 225, GREEN, "[*/] - scale z / reset scale");
	if (data->options.projection_type == PROJECTION_PARALLEL)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 245, GREEN, "P - projection central");
	}
	else
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 245, GREEN, "P - projection parallel");
	}
}

void redraw_scene(struct s_data *data)
{
	clock_t start;

	start = clock();
	if (data->options.target == TARGET_IMAGE)
	{
		ft_memset(data->image.image, 0, data->window_y * data->window_x * 4);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_points(data, &data->points, &data->basic);
	if (data->options.target == TARGET_IMAGE)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img_ptr, 0, 0);
	}
	if (data->options.show_help)
	{
		draw_help(data);
	}
	data->fps = CLOCKS_PER_SEC / (clock() - start);
}

void handle_options(int key, struct s_data *data)
{
	if (key == H)
	{
		data->options.show_help = !data->options.show_help;
	}
	else if (key == L)
	{
		if (data->options.line_method == LINE_BRESENHAM)
		{
			data->options.line_method = LINE_WU;
			data->draw_line = &draw_line_Wu;
		}
		else
		{
			data->options.line_method = LINE_BRESENHAM;
			data->draw_line = &draw_line;
		}
	}
	else if (key == V)
	{
		data->options.diagonal_lines = !data->options.diagonal_lines;
	}
	else if (key == O)
	{
		data->options.cut_line_window_border = !data->options.cut_line_window_border;
	}
	else if (key == F)
	{
		data->options.show_framerate = !data->options.show_framerate;
	}
	else if (key == J)
	{
		if (data->options.target == TARGET_SCREEN)
		{
			data->options.target = TARGET_IMAGE;
			data->pixel_put = &pixel_put_image;
		}
		else
		{
			data->options.target = TARGET_SCREEN;
			data->pixel_put = &mlx_pixel_put;
		}
	}
	else if (key == P)
	{
		if (data->options.projection_type == PROJECTION_PARALLEL)
		{
			data->options.projection_type = PROJECTION_CENTRAL;
			data->basic.arr[0][3] = 5;
			data->basic.arr[1][3] = 5;
		}
		else
		{
			data->options.projection_type = PROJECTION_PARALLEL;
		}
	}
	else
	{
		ft_printf("key = %d\n", key);
	}
}

void free_memory(struct s_data *data)
{
	//free
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
}

int mouse_hook(int button, int x, int y, void *p)
{
	ft_printf("mouse: x = %d, y = %d\n", x, y);
	return (0);
}

void move(struct s_matrix4 *basic)
{

}

void rotate(struct s_matrix4 *basic)
{

}

int key_hook(int key, void *param)
{
	struct s_data *data;
	int xstep = 5;
	int ystep = 5;
	float scale_step = 0.1;
	float angle = 3.14 * 0.01;
	struct s_matrix4 move;

	identity_matrix4(&move);
	data = param;
	if (key == ESC)
	{
		free_memory(data);
		exit(0);
	}
	else if (key == W)
	{
		move.arr[3][1] = -ystep;
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == A)
	{
		move.arr[3][0] = -xstep;
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == S)
	{
		move.arr[3][1] = ystep;
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == D)
	{
		move.arr[3][0] = xstep;
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == Q)
	{
		move.arr[0][0] = cos(angle);
		move.arr[0][1] = -sin(angle);
		move.arr[1][0] = sin(angle);
		move.arr[1][1] = cos(angle);
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == E)
	{
		angle = -angle;
		move.arr[0][0] = cos(angle);
		move.arr[0][1] = -sin(angle);
		move.arr[1][0] = sin(angle);
		move.arr[1][1] = cos(angle);
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == UP)
	{
		angle = -angle;
		move.arr[1][1] = cos(angle);
		move.arr[1][2] = -sin(angle);
		move.arr[2][1] = sin(angle);
		move.arr[2][2] = cos(angle);
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == DOWN)
	{
		move.arr[1][1] = cos(angle);
		move.arr[1][2] = -sin(angle);
		move.arr[2][1] = sin(angle);
		move.arr[2][2] = cos(angle);
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == LEFT)
	{
		move.arr[0][0] = cos(angle);
		move.arr[0][2] = sin(angle);
		move.arr[2][0] = -sin(angle);
		move.arr[2][2] = cos(angle);
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == RIGHT)
	{
		angle = -angle;
		move.arr[0][0] = cos(angle);
		move.arr[0][2] = sin(angle);
		move.arr[2][0] = -sin(angle);
		move.arr[2][2] = cos(angle);
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == NUMPAD_PLUS)
	{
		move.arr[0][0] = 1 + scale_step;
		move.arr[1][1] = 1 + scale_step;
		//move.arr
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == NUMPAD_MINUS)
	{
		move.arr[0][0] = 1 - scale_step;
		move.arr[1][1] = 1 - scale_step;
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == NUMPAD_ASTERISK)
	{
		data->basic.arr[2][3] += 1;
	}
	else if (key == NUMPAD_SLASH)
	{
		data->basic.arr[2][3] = 0;
	}
	else if (key == R)
	{
		identity_matrix4(&data->basic);
		center_surface(data);
	}
	else if (key == C)
	{
		struct s_matrix4 m;
		int xcenter;
		int ycenter;

		identity_matrix4(&m);
		xcenter = array_point_at(array2_point_at(&data->points, array2_point_size(&data->points) - 1), array_point_size(array2_point_at(&data->points, array2_point_size(&data->points) - 1)) - 1).x / 2 ;
		ycenter = array_point_at(array2_point_at(&data->points, array2_point_size(&data->points) - 1), array_point_size(array2_point_at(&data->points, array2_point_size(&data->points) - 1)) - 1).y / 2;
		/*m.arr[3][0] = - xcenter;
		m.arr[3][1] =  - ycenter;
		matrix4_multiply_matrix4(&data->basic, &m);*/
		data->basic.arr[0][0] *= 0.9;
		data->basic.arr[1][1] *= 0.9;
	}
	handle_options(key, data);
	redraw_scene(data);
	return (0);
}

void init_options(struct s_options *options)
{
	options->show_help = 1;
	options->diagonal_lines = 0;
	options->line_method = LINE_BRESENHAM;
	options->cut_line_window_border = 1;
	options->show_framerate = 1;
	options->target = TARGET_IMAGE;
	options->projection_type = PROJECTION_PARALLEL;
}

void demo_scene(struct s_data *data)
{
	draw_line(data, make_point(200, 200, 0), make_point(100, 100, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(300, 100, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(100, 300, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(300, 300, 0), RED);

	draw_line(data, make_point(200, 200, 0), make_point(200, 100, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(200, 300, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(100, 200, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(300, 200, 0), RED);

	draw_line(data, make_point(200, 200, 0), make_point(150, 100, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(250, 100, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(150, 300, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(250, 300, 0), RED);

	draw_line(data, make_point(200, 200, 0), make_point(100, 150, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(300, 150, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(100, 250, 0), RED);
	draw_line(data, make_point(200, 200, 0), make_point(300, 250, 0), RED);

	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 200, 200, GREEN);
}

void create_image(struct s_data *data)
{
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, data->window_x, data->window_y);
	data->image.image = mlx_get_data_addr(data->image.img_ptr, &data->image.bits_per_pixel, &data->image.size_line, &data->image.endian);
}

int main(int argc, char *argv[])
{
	struct s_data data;

	get_data(&data);
	if (argc != 2)
	{
		ft_printf("usage: ./fdf filename\n");
		return (1);
	}
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		ft_printf("Error: Failed to set up the connection to X server.\n");
		exit(1);
	}
	data.window_x = 1280;
	data.window_y = 720;
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.window_x, data.window_y, "Fdf");
	if (!data.win_ptr)
	{
		ft_printf("Error: Failed to create window.\n");
		exit(1);
	}
	data.fps = 0;
	data.pixel_put = &pixel_put_image;
	data.draw_line = &draw_line;
	create_image(&data);
	init_options(&data.options);

	/*demo_scene(&data);
	mlx_loop(data.mlx_ptr);*/

	array2_point_init(&data.points);
	if (!read_points(&data.points, argv[1]))
	{
		array2_point_destroy(&data.points);
		ft_printf("error\n");
		return (1);
	}
	data.xcenter = data.window_x / 2;
	data.ycenter = data.window_y / 2;
	identity_matrix4(&data.basic);
	center_surface(&data);
	//center_scale(&data);
	redraw_scene(&data);

	mlx_hook(data.win_ptr, 2, 0, &key_hook, &data);
	mlx_hook(data.win_ptr, 5, 0, &mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
	array2_point_destroy(&data.points);
	return 0;
}
