#include "keyboard.h"
#include "matrix4.h"
#include "stdlib.h"
#include "math.h"
#include "options.h"
#include "draw.h"

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
		data->ycamera -= ystep;
	}
	else if (key == A)
	{
		data->xcamera -= xstep;
	}
	else if (key == S)
	{
		data->ycamera += ystep;
	}
	else if (key == D)
	{
		data->xcamera += xstep;
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
		data->options.zscale *= (1 + scale_step);
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == NUMPAD_MINUS)
	{
		move.arr[0][0] = 1 - scale_step;
		move.arr[1][1] = 1 - scale_step;
		data->options.zscale *= (1 - scale_step);
		matrix4_multiply_matrix4(&data->basic, &move);
	}
	else if (key == NUMPAD_ASTERISK)
	{
		data->options.zscale *= (1 + scale_step);
	}
	else if (key == NUMPAD_SLASH)
	{
		data->options.zscale *= (1 - scale_step);
	}
	else if (key == R)
	{
		identity_matrix4(&data->basic);
		center_surface(data);
	}
	else if (key == C)
	{
		struct s_matrix4 m;

		identity_matrix4(&m);
		data->basic.arr[0][0] *= 0.9;
		data->basic.arr[1][1] *= 0.9;
	}
	handle_options(key, &data->options, &data->draw_context);
	redraw_scene(data);
	return (0);
}