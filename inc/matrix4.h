/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:34:18 by myaremen          #+#    #+#             */
/*   Updated: 2019/03/29 18:34:20 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX4_H
# define MATRIX4_H

struct	s_matrix4
{
	float arr[4][4];
};

void	identity_matrix4(struct s_matrix4 *m);

void	matrix4_multiply_matrix4(struct s_matrix4 *l,
		const struct s_matrix4 *r);

#endif
