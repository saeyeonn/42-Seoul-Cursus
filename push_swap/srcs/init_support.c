/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:10:56 by hbyeon            #+#    #+#             */
/*   Updated: 2023/06/24 20:41:58 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_vars(t_vars *vars)
{
	vars->i = 0;
	vars->tmp = NULL;
}

void	destroy_stacks(t_list **a, t_list **b)
{
	if (*a)
		ft_lstclear(a, free);
	if (*b)
		ft_lstclear(b, free);
	exit (0);
}

void	init_list(char **argv, t_list **a, t_vars *var, int argc)
{
	while (var->i < argc)
	{
		if (!duplicate_checker(*a, ft_atoi(argv[var->i])))
		{
			ft_printf("[Error] The Value \"%s\" Is Duplicated\n", argv[var->i]);
			destroy_stacks(a, a);
		}
		var->tmp = ft_calloc(1, sizeof(int));
		*var->tmp = ft_atoi(argv[var->i]);
		ft_lstadd_back(a, ft_lstnew(var->tmp));
		var->i++;
	}
}
