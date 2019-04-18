/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:35:11 by myaremen          #+#    #+#             */
/*   Updated: 2019/03/29 18:35:12 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4.h"
#include "libft.h"

void identity_matrix4(struct s_matrix4 *m)
{
	ft_memset(m, 0, sizeof(struct s_matrix4));
	m->arr[0][0] = 1;
	m->arr[1][1] = 1;
	m->arr[2][2] = 1;
	m->arr[3][3] = 1;
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