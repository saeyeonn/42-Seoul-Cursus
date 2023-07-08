/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:07:51 by hbyeon            #+#    #+#             */
/*   Updated: 2023/06/24 20:08:58 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **a, int flag)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, temp);
	if (flag == 0)
		ft_printf("ra\n");
}

void	rb(t_list **b, int flag)
{
	t_list	*temp;

	temp = *b;
	*b = (*b)->next;
	ft_lstadd_back(b, temp);
	if (flag == 0)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 1);
	rb(b, 1);
	ft_printf("rr\n");
}

void	rra(t_list **a, int flag)
{
	t_list	*temp;
	t_list	*temp2;

	if ((*a)->next == NULL)
		return ;
	temp2 = *a;
	while (temp2->next->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp = temp2->next;
	temp->next = *a;
	*a = temp;
	temp2->next = NULL;
	if (flag == 0)
		ft_printf("rra\n");
}

void	rrb(t_list **b, int flag)
{
	t_list	*temp;
	t_list	*temp2;

	if ((*b)->next == NULL)
		return ;
	temp2 = *b;
	while (temp2->next->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp = temp2->next;
	temp->next = *b;
	*b = temp;
	temp2->next = NULL;
	if (flag == 0)
		ft_printf("rrb\n");
}
