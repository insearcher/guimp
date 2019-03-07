/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:18:57 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/13 02:15:26 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_current_node(int const fd, t_list **root)
{
	t_list	*cur;

	if (!root)
		return (NULL);
	cur = *root;
	while (cur)
	{
		if (cur->content_size == (size_t)fd)
			return (cur);
		cur = cur->next;
	}
	cur = ft_lstnew("\0", (size_t)fd);
	ft_lstadd(root, cur);
	return (*root);
}

static size_t	get_length(char *line)
{
	size_t	res;

	res = 0;
	while (line[res] && line[res] != '\n')
		++res;
	return (res);
}

static char		*crop_str(t_list *node, size_t s)
{
	char	*res;

	if (!(res = ft_strsub(node->content, s, ft_strlen(node->content) - s)))
		return (NULL);
	free(node->content);
	return (res);
}

static int		get_next_line2(char **l, int s, t_list *c)
{
	if (s < BUFF_SIZE && (!(c->content) || !ft_strlen(c->content)))
		return (0);
	s = get_length(c->content);
	if (!(*l = ft_strnew(s + 1)))
		return (-1);
	ft_strncpy(*l, c->content, s);
	if (s < (int)ft_strlen(c->content))
	{
		if (!(c->content = crop_str(c, s + 1)))
			return (-1);
	}
	else
		ft_strdel((char **)&(c->content));
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*root;
	t_list			*cur;
	int				size;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	cur = get_current_node(fd, &root);
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		*line = cur->content;
		if (!(cur->content = ft_strjoin(cur->content, buf)))
			return (-1);
		free(*line);
		if (ft_strchr(cur->content, '\n'))
			break ;
	}
	return (get_next_line2(line, size, cur));
}
