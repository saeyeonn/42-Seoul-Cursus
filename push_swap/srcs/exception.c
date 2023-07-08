/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:42:54 by hbyeon            #+#    #+#             */
/*   Updated: 2023/06/24 20:46:04 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	not_integer_exception(char *value)
{
	ft_printf("[Error] The Value \"%s\" Is Not Integer\n", value);
	exit(0);
}

void	empty_string_exception(void)
{
	ft_printf("[Error] Empty String Input\n");
	exit(0);
}

void	only_whitespace_exception(char *value)
{
	ft_printf("[Error] The input \"%s\" is only whitespace.\n", value);
	exit(0);
}
