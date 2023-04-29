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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list {
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

void	ft_free(t_list *node, int self, int str);
t_list	*ft_lstnew(int fd);
t_list	*ft_findlst(t_list **lst, int fd);
void	ft_delnode(t_list **lst, t_list *node);
char	*get_next_line(int fd);

int		ft_findlen(char *str, int nl, int end);
int		ft_strnode(t_list *node, char *buff, int byte);
char	*ft_substr(char *str, int start, int len, int nl);
char	*ft_newline(t_list *node);

#endif