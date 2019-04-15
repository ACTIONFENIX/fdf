/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:17:35 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/07 19:48:52 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_stralloc(char const *s, size_t len)
{
	char *str;

	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, s, len);
	str[len] = '\0';
	return (str);
}

static size_t	ft_strtrim_init(char const *s, size_t *diff, size_t *s_len)
{
	*diff = 0;
	*s_len = ft_strlen(s);
	return (*s_len - 1);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	diff;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	i = ft_strtrim_init(s, &diff, &s_len);
	while (i && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		--i;
		++diff;
	}
	if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++diff;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		++i;
		++diff;
	}
	if (diff > s_len)
		diff = s_len;
	str = ft_stralloc(s + i, s_len - diff);
	return (str);
}
