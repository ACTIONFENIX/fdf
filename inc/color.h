/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:33:56 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/16 16:33:58 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

#include <stdint.h>

struct s_color
{
	uint8_t b;
	uint8_t g;
	uint8_t r;
	uint8_t a;
};

union u_color
{
	uint32_t color;
	struct s_color scolor;
};

#endif