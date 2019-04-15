/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:11:37 by myaremen          #+#    #+#             */
/*   Updated: 2019/01/24 21:11:39 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_lltoa_len(long long int n, int leading_zeros, int sign)
{
	int len;

	len = 0;
	if (leading_zeros < 0)
		leading_zeros = 0;
	if (n == 0)
	{
		len = 2;
	}
	if (n < 0 || (n > 0 && sign))
		++len;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len + leading_zeros);
}

void	ft_printf_lltoa_leading_zeros(char *str, int leading_zeros)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (leading_zeros < 0)
		leading_zeros = 0;
	while (j < leading_zeros)
	{
		str[i++] = '0';
		++j;
	}
}

char	*ft_printf_lltoa(long long int n, int leading_zeros, int sign)
{
	char	*str;
	int		i;
	int		len;

	if (leading_zeros < 0)
		leading_zeros = 0;
	len = ft_printf_lltoa_len(n, leading_zeros, sign);
	str = (char *)malloc(len + 1);
	i = 0;
	if (n >= 0 && sign)
		str[i++] = '+';
	if (n < 0)
		str[i++] = '-';
	if (n == 0)
		str[i++] = '0';
	ft_printf_lltoa_leading_zeros(str + i, leading_zeros);
	i = len - 1;
	while (n)
	{
		str[i--] = '0' + ft_llabs(n % 10);
		n /= 10;
	}
	str[len] = '\0';
	return (str);
}

int		printf_numbers_count(long long int n)
{
	int len;

	len = 0;
	if (n == 0)
	{
		len = 1;
	}
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

void	printf_toupper(char *pc)
{
	if (ft_islower(*pc))
		*pc = ft_toupper(*pc);
}
