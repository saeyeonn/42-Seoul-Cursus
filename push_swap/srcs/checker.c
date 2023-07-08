/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:46:06 by hbyeon            #+#    #+#             */
/*   Updated: 2023/06/24 20:45:17 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	int_checker(char *num, char *return_value)
{
	int	sign;
	int	flag;
	int	res;

	if (ft_strlen(num) > 11 || ft_strlen(num) == 0)
		not_integer_exception(return_value);
	if (*num == '0' && ft_isdigit(*(num + 1)))
		not_integer_exception(return_value);
	res = 0;
	sign = 1;
	if (((*num == '+' || *num == '-') && *(num + 1) != '0'))
		num++;
	while (*num)
	{
		if (!ft_isdigit(*num))
			not_integer_exception(return_value);
		flag = res;
		res = (res * 10) + (*num - '0');
		if ((flag > res && sign == -1) || (flag > res && sign == 1))
			not_integer_exception(return_value);
		num++;
	}
}

int	duplicate_checker(t_list *a, int nbr)
{
	while (a)
	{
		if (*a->content == nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_sorted(t_list *a)
{
	while (a->next)
	{
		if (*a->content > *a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	blank_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			empty_string_exception();
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] != ' ')
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (!flag)
			only_whitespace_exception(argv[i]);
	}
}
