/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:56:40 by myaremen          #+#    #+#             */
/*   Updated: 2019/04/18 16:56:41 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

struct s_data *get_data(struct s_data *set_data)
{
	static struct s_data *save_data = 0;

	if (save_data == 0)
	{
		save_data = set_data;
	}
	return save_data;
}
