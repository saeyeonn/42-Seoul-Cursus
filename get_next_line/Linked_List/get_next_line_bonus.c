/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:55:03 by saelim            #+#    #+#             */
/*   Updated: 2023/01/04 15:02:10 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew(int fd)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->fd = fd;
	node->str = NULL;
	node->next = NULL;
	return (node);
}

t_list	*ft_findlst(t_list **lst, int fd)
{
	t_list	*find;
	t_list	*org;

	org = *lst;
	if (!*lst)
	{
		*lst = ft_lstnew(fd);
		if (!*lst)
			return (0);
		return (*lst);
	}
	while ((*lst)->next && (*lst)->fd != fd)
		*lst = (*lst)->next;
	if ((*lst)->fd == fd)
		find = *lst;
	else
	{
		find = ft_lstnew(fd);
		(*lst)->next = find;
	}
	*lst = org;
	return (find);
}

void	ft_free(t_list *node, int single, int str)
{
	if (node)
	{
		if (str && node->str)
		{
			free(node->str);
			node->str = NULL;
		}
		if (single)
		{
			free(node);
			node = NULL;
		}
	}
}

void	ft_delnode(t_list **lst, t_list *node)
{
	t_list	*prev;
	t_list	*find;
	t_list	*org;

	org = *lst;
	prev = *lst;
	while (prev->next != node && prev != node)
		prev = prev->next;
	if (prev == node)
	{
		*lst = prev->next;
		ft_free(prev, 1, 1);
	}
	else
	{
		find = prev->next;
		prev->next = find->next;
		ft_free(find, 1, 1);
		(*lst) = org;
	}
}

char	*get_next_line(int fd)
{
	int				byte;
	char			buff[BUFFER_SIZE + 1];
	t_list			*node;
	static t_list	*lst = NULL;

	byte = 1;
	node = ft_findlst(&lst, fd);
	buff[BUFFER_SIZE] = '\0';
	while (byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		if (ft_strnode(node, buff, byte) >= 0)
			break ;
	}
	if (node->str && byte >= 0)
		return (ft_newline(node));
	ft_delnode(&lst, node);
	return (NULL);
}
