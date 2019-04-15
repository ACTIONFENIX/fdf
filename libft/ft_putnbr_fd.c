/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:24:00 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/06 19:51:59 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recur_print(long long int n, int fd)
{
	if (n == 0)
		return ;
	ft_recur_print(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long long int n_cpy;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	n_cpy = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n_cpy *= -1;
	}
	ft_recur_print(n_cpy, fd);
}
