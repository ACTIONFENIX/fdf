/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:13:40 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 18:13:41 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "stdbool.h"
# include "array2_point.h"

bool parse_line(struct s_array2_point *sarr, char *line);

bool is_data_full(struct s_array2_point *sarr);

bool read_points(struct s_array2_point *sarr, const char *filename);

#endif
