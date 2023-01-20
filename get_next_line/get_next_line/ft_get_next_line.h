/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:01:32 by saelim            #+#    #+#             */
/*   Updated: 2023/01/10 21:01:32 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
    char *str;
    char *new;
    int fd;
    t_list *next;
}   t_list;

t_list *find_fd(int fd, t_list *lst);
int find_next(char *str, t_list *node);
void lst_with_new(char *str, t_list *node);
char *cut_line (char *str, t_list *node);
char *ft_get_next_line(int fd);

#include <unistd.h>
#include <stdlib.h>

# endif