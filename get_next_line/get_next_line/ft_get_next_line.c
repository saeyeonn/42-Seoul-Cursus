/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:01:00 by saelim            #+#    #+#             */
/*   Updated: 2023/01/10 21:01:00 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

t_list *find_fd(int fd, t_list *lst)
{
    t_list *current;
    t_list *head;
    int i;

    head = lst;
    i = 0;
       if (!lst || i != fd)
    {
        current = newlst(*lst);
        if (!current)
            return (NULL);
    }
    while (i++ < fd && lst->next)
        lst = lst->next;
    if (i != fd)
    {
        current = newlst(*lst);
        if (!current)
            return (NULL);
        lst->next = current;
    }
    lst = head;
    return (current);
}

void lst_with_new(char *str, t_list *node)
{
    char *new;
    char *n_ptr;

    n_ptr = new;
    while (*str != '\n')
        node->(new++) = *str++;
        *n_ptr++ = *str++;
        
}

int find_next(char *str, t_list *node) // 개행 없으면 str + str 생성 후 붙이기 , 개행 있으면 뒷문자 노드 생성후 붙이기
{
    while (*str)
    {
        if (*str == '\n')
        {
            lst_with_new(str, node); // str 따로 빼놓기 -> 기존 str free -> 새 str 연결 
            return (1);
        }
        str++;  
    }
    if(*str = '\0')
        lst_only_add(str, node);
    return(-1);
}

char *cut_line (char *str, t_list *node)
{
    char *res;

    return (res);
}

char *ft_get_next_line(int fd)
{
    static t_list *lst = NULL;
    t_list *node;
    char *line;
    char str[BUFFER_SIZE + 1];
    int byte;

    str[BUFFER_SIZE] = '\0';
    node = find_fd(fd, lst); // move to fd node
    while (byte > 0)
    {
        byte = read(fd, str, BUFFER_SIZE);
        if (byte <= 0)
            break;
        if (find_next(str, node) >= 0) // found \n or EOF  
            break;
    }
    if (node->str && byte > 0)
        return (cut_line(str, &node)); // return one line
    return (NULL);
}