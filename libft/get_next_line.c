/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaremen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:32:18 by myaremen          #+#    #+#             */
/*   Updated: 2018/11/25 13:49:45 by myaremen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	g_gnl;

static t_list	*get_fd_buffer(const int fd)
{
	t_list *lst;

	lst = g_gnl.multifd;
	while (lst && (int)lst->content_size != fd)
		lst = lst->next;
	if (!lst)
	{
		lst = ft_lstnew(NULL, 0);
		lst->content = ft_strnew(0);
		lst->content_size = (size_t)fd;
		ft_lstadd(&g_gnl.multifd, lst);
	}
	return (lst);
}

static void		realloc_str(char **str, size_t new_size)
{
	char	*old_str;
	size_t	old_size;

	if (!*str)
		*str = ft_strnew(0);
	old_size = ft_strlen(*str);
	if (new_size <= old_size)
		return ;
	old_str = *str;
	*str = ft_strnew(new_size);
	if (*str)
		ft_strncpy(*str, old_str, old_size);
	free(old_str);
}

static int		read_remain(char **line, t_list *fd_buf)
{
	char	*find;
	char	find_end;
	char	*new_remain;
	size_t	line_size;

	find = ft_strchr(fd_buf->content, '\n');
	if (!find)
		find = fd_buf->content + ft_strlen(fd_buf->content);
	find_end = *find;
	line_size = find - (char*)fd_buf->content;
	realloc_str(line, ft_strlen(*line) + line_size);
	if (!*line)
		return (READ_FAILURE);
	ft_strncat(*line, fd_buf->content, line_size);
	new_remain = ft_strnew(ft_strlen(fd_buf->content) - line_size);
	if (!new_remain)
		return (READ_FAILURE);
	if (*find == '\n')
		++find;
	ft_strcpy(new_remain, find);
	free(fd_buf->content);
	fd_buf->content = new_remain;
	if (find_end == '\n')
		return (READ_SUCCESS);
	return (READ_ING);
}

static int		read_buffer(char **line, t_list *fd_buf)
{
	long int	count;

	if (!ft_strlen(fd_buf->content))
	{
		count = read(fd_buf->content_size, g_gnl.buff, BUFF_SIZE);
		if (count <= 0)
		{
			if (ft_strlen(*line))
				return (READ_SUCCESS);
			else
				return (count < 0 ? READ_FAILURE : READ_END);
		}
		realloc_str((char**)&(fd_buf->content), count);
		if (!fd_buf->content)
			return (READ_FAILURE);
		ft_strncpy(fd_buf->content, g_gnl.buff, count);
		return (READ_ING);
	}
	else
	{
		return (read_remain(line, fd_buf));
	}
}

int				get_next_line(const int fd, char **line)
{
	t_list		*fd_buf;
	int			status;

	if (!line || fd < 0)
		return (READ_FAILURE);
	fd_buf = get_fd_buffer(fd);
	if (!fd_buf)
		return (READ_FAILURE);
	*line = ft_strnew(0);
	if (!*line)
		return (READ_FAILURE);
	status = READ_ING;
	while (status == READ_ING)
		status = read_buffer(line, fd_buf);
	return (status);
}
