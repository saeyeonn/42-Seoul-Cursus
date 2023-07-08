/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smaller_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:51:18 by apereira          #+#    #+#             */
/*   Updated: 2023/06/21 17:27:39 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_argc_less_3(t_list **a)
{
	if (*(*a)->content > *(*a)->next->content && (*a)->next->next
		&& *(*a)->content < *(*a)->next->next->content)
		sa(a, 0);
	if (check_sorted(*a))
		return ;
	if (*(*a)->content < *(*a)->next->content)
	{
		rra(a, 0);
		if (check_sorted(*a))
			return ;
		sa(a, 0);
	}
	if (check_sorted(*a))
		return ;
	if (*(*a)->content > *(*a)->next->content)
	{
		ra(a, 0);
		if (check_sorted(*a))
			return ;
		sa(a, 0);
		if (check_sorted(*a))
			return ;
	}
}

void	sort_argc_equals_4(t_list **a, t_list **b)
{
	find_highest_numbers(a, b);
	sort_argc_less_3(a);
	pa(a, b);
	ra(a, 0);
}

void	sort_argc_equals_5(t_list **a, t_list **b)
{
	find_highest_numbers(a, b);
	find_highest_numbers(a, b);
	sort_argc_less_3(a);
	pa(a, b);
	ra(a, 0);
	pa(a, b);
	ra(a, 0);
}

void	find_highest_numbers(t_list **a, t_list **b)
{
	int		bigpos;
	t_list	*temp;
	int		nbr;
	int		i;

	bigpos = 0;
	temp = (*a);
	nbr = *(*a)->content;
	i = 0;
	while (temp->content)
	{
		i++;
		if (nbr < *temp->content)
		{
			nbr = *temp->content;
			bigpos = i;
		}
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	push_highest_numbers(a, b, bigpos);
}

void	push_highest_numbers(t_list	**a, t_list **b, int bigpos)
{
	if (bigpos == 2)
		ra(a, 0);
	if (bigpos == 3)
	{
		ra(a, 0);
		ra(a, 0);
	}
	if (bigpos == 4 && (*a)->next->next->next->next)
	{
		rra(a, 0);
		rra(a, 0);
	}
	else if (bigpos == 4)
		rra(a, 0);
	if (bigpos == 5)
		rra(a, 0);
	pb(a, b);
}
