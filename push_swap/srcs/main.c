/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:31:13 by apereira          #+#    #+#             */
/*   Updated: 2023/06/24 20:46:31 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	validate_argv(int argc, char **argv)
{	
	int	idx;

	if (argc == 0)
		exit (0);
	idx = -1;
	while (argv[++idx])
		int_checker(argv[idx], argv[idx]);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_vars	var;
	int		cnt;
	char	**parsed_argv;

	a = NULL;
	b = NULL;
	blank_checker(argc, argv);
	cnt = count_parsed_argv(argv);
	parsed_argv = parse_argv(cnt, argv);
	validate_argv(cnt, parsed_argv);
	init_vars(&var);
	init_list(parsed_argv, &a, &var, cnt);
	ft_freeall(parsed_argv, cnt);
	sort_factory(cnt, a, b);
	return (0);
}
