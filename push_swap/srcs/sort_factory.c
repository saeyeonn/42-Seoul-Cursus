/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:30:40 by hbyeon            #+#    #+#             */
/*   Updated: 2023/06/24 20:06:34 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_factory(int argc, t_list *a, t_list *b)
{
	if (check_sorted(a))
		destroy_stacks(&a, &b);
	if (argc <= 3)
		sort_argc_less_3(&a);
	else if (argc <= 4)
		sort_argc_equals_4(&a, &b);
	else if (argc <= 5)
		sort_argc_equals_5(&a, &b);
	else
		radix_sort(&a, &b);
	destroy_stacks(&a, &b);
}
