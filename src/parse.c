/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:15:02 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 18:15:03 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "array_point.h"
#include "point.h"
#include <unistd.h>
#include <fcntl.h>

#define DEFAULT_COLOR BLUE

bool parse_line(struct s_array2_point *sarr, char *line)
{
	struct s_array_point arr;
	int x;
	int z;
	static int y = 0;
	struct s_point point;
	int xstep = 20;
	int ystep = 20;
	int color;

	x = 0;
	array_point_init(&arr);
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != '+' && *line != '-' && *line != ' ')
		{
			return (0);
		}
		z = ft_atoi(line) * 5;
		line = skip_atoi_number(line);

		color = 0;
		if (*line == ',')
		{
			++line;
			color = ft_atox(line);
			line = skip_atox_number(line);
		}
		if (color == 0)
		{
			color = DEFAULT_COLOR;
		}

		while (ft_isspace(*line))
		{
			++line;
		}
		point = make_point(x, y, z, color);
		array_point_push_back(&arr, &point);
		x += xstep;
	}
	y += ystep;
	array2_point_push_back(sarr, &arr);
	return (1);
}

bool is_data_full(struct s_array2_point *sarr)
{
	size_t i;
	size_t line_size;
	struct s_array_point *arr;

	line_size = array_point_size(array2_point_front(sarr));
	i = 1;
	while (i < array2_point_size(sarr))
	{
		arr = array2_point_at(sarr, i);
		if (array_point_size(arr) != line_size)
		{
			return (0);
		}
		++i;
	}
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
	return (is_data_full(sarr));
}
