/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:18:26 by apereira          #+#    #+#             */
/*   Updated: 2023/06/24 12:05:14 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_element3(t_moves *local, int sizea, int sizeb)
{
	if (local->ra > sizea / 2)
	{
		local->rra = sizea - local->ra;
		local->ra = 0;
	}
	if (local->rb > sizeb / 2)
	{
		local->rrb = sizeb - local->rb;
		local->rb = 0;
	}
	while (local->ra > 0 && local->rb > 0)
	{
		local->ra--;
		local->rb--;
		local->rr++;
	}
	while ((local->rra > 0 && local->rrb > 0))
	{
		local->rra--;
		local->rrb--;
		local->rrr++;
	}
}

// 요소가 B 스택에서 가장 큰 요소 또는 가장 작은 요소인지 확인합니다.
// 그렇다면, B를 회전하여 해당 요소의 가장 큰 숫자가 맨 위에 올 때까지 회전하는 횟수를 계산합니다.
// 그렇지 않으면, 요소를 B의 올바른 위치에 놓기 위해 필요한 RB 회전 횟수를 계산하기 위해 RB 함수를 시뮬레이션합니다.
void	first_element2(t_list *element, t_list *b,
			t_list *last, t_moves *local)
{
	if (smaller(element, b) || bigger(element, b))
	{
		while (*b->content != *biggest(b)->content)
		{
			local->rb++;
			b = b->next;
		}
	}
	else
	{
		while (b && (*element->content < *b->content
				|| *element->content > *last->content))
		{
			local->rb++;
			if (last->next == NULL)
				last = b;
			else
				last = last->next;
			b = b->next;
		}
	}
}

// 주어진 요소가 B 스택의 가장 큰 요소보다 큰지 또는 가장 작은 요소보다 작은지 확인합니다.
// 만약 그렇다면, B 스택의 가장 큰 요소가 맨 위에 올 때까지 RB(Rotate Backward)를 실행합니다.
// 만약 해당 요소가 가장 큰 요소나 가장 작은 요소가 아니라면, 
// 스택의 중간에 해당 요소를 올바른 위치에 놓기 위해 필요한 RB 횟수를 계산합니다.
void	first_element(t_list *element, t_list *b, t_moves *moves, int sizea)
{
	t_moves	local;
	t_list	*last;
	int		sizeb;

	sizeb = ft_lstsize(b);
	moves->ra = 0;
	local.ra = 0;
	last = ft_lstlast(b);
	moves_reset(&local);
	first_element2(element, b, last, &local);
	first_element3(&local, sizea, sizeb);
	moves->ra = local.ra;
	moves->rb = local.rb;
	moves->rr = local.rr;
	moves->rrb = local.rrb;
	moves->rra = local.rra;
	moves->rrr = local.rrr;
}
