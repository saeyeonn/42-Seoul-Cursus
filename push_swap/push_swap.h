/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyeon <hbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:48:33 by apereira          #+#    #+#             */
/*   Updated: 2023/06/24 20:46:05 by hbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_vars
{
	int				i;
	int				*tmp;
}				t_vars;

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}				t_list;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}				t_moves;
char		*ft_strdup(const char *s1);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_lstadd_back(t_list **lst, t_list *newx);
void		ft_lstclear(t_list **lst, void (*del)(void *));
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
int			ft_printf(const char *f, ...);
int			ft_specifier(va_list ap, const char *f);
int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putnbr(int n, int *cnt);
int			ft_putunbr(unsigned int n, int *cnt);
int			ft_sw(unsigned long long nb, char f, int *cnt);
int			ft_strlen(const char *s);
int			ft_isdigit(char c);
void		ft_freeall(char **res, int i);
char		**ft_split(char const *s, char c);
void		int_checker(char *num, char *return_value);
int			count_parsed_argv(char **argv);
char		**parse_argv(int cnt, char **argv);
void		blank_checker(int argc, char **argv);
void		space_checker(int argc, char **argv);
int			duplicate_checker(t_list *a, int nbr);
void		init_list(char **argv, t_list **a, t_vars *var, int argc);
void		validate_argv(int argc, char **argv);
void		not_integer_exception(char *value);
void		sort_factory(int argc, t_list *a, t_list *b);
void		add_malloc_list(char **main_storage, char *string, \
			char **new_main_storage);
void		empty_string_exception(void);
void		only_whitespace_exception(char *value);
int			ft_isspace(char *str);
void		sa(t_list **a, int flag);
void		sb(t_list **b, int flag);
void		ss(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		ra(t_list **a, int flag);
void		rb(t_list **b, int flag);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a, int flag);
void		rrb(t_list **b, int flag);
void		rrr(t_list **b, t_list **a);
void		print_stacks(t_list *a, char c);
void		init_vars(t_vars *vars);
void		destroy_stacks(t_list **a, t_list **b);
void		go_back(t_list **a);
int			check_sorted(t_list *a);
void		moves_reset(t_moves *moves);
void		sort_argc_less_3(t_list **a);
void		sort_argc_equals_4(t_list **a, t_list **b);
void		sort_argc_equals_5(t_list **a, t_list **b);
void		find_highest_numbers(t_list **a, t_list **b);
void		push_highest_numbers(t_list	**a, t_list **b, int bigpos);
void		radix_sort(t_list **a, t_list **b);
t_list		*biggest(t_list *b);
int			bigger(t_list *element, t_list *b);
t_list		*smallest(t_list *b);
int			smaller(t_list *element, t_list *b);
void		fewer_moves_element(t_list *node, t_list *first, \
			t_moves *moves, int sizea);
void		first_element(t_list *node, t_list *first, \
			t_moves *moves, int sizea);

#endif