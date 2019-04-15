/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:24:07 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/07 19:36:31 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strsplit_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			++i;
		if (s[i] && s[i] != c)
			++len;
		while (s[i] && s[i] != c)
			++i;
	}
	return (len);
}

static char		*rowalloc(char const *s, size_t i, size_t count)
{
	char	*row;

	row = ft_strnew(count);
	if (row)
	{
		ft_strncpy(row, s + i - count, count);
		row[count] = '\0';
	}
	return (row);
}

static char		**arr_dealloc(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		++i;
	}
	free(arr);
	return (NULL);
}

static char		**arralloc(char const *s, char c, size_t len)
{
	char	**arr;
	size_t	i;
	size_t	row;
	size_t	count;

	arr = (char**)malloc(sizeof(char*) * (len + 1));
	i = 0;
	row = 0;
	while (arr && s[i])
	{
		while (s[i] && s[i] == c)
			++i;
		count = 0;
		while (s[i] && s[i] != c)
		{
			++count;
			++i;
		}
		arr[row] = rowalloc(s, i, count);
		if (!arr[row])
			return (arr_dealloc(arr, row));
		++row;
	}
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strsplit_len(s, c);
	arr = arralloc(s, c, len);
	if (arr)
		arr[len] = NULL;
	return (arr);
}
