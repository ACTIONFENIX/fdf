/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:29:25 by myaremen          #+#    #+#             */
/*   Updated: 2019/03/29 14:29:26 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_POINT_H
# define FDF_POINT_H

#include "color.h"

struct s_point
{
	int x;
	int y;
	int z;
	union u_color color;
};

#endif
