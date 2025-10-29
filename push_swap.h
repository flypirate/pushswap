/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertogm <albertogm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:37:02 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/16 20:25:25 by albertogm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "resources/printf/ft_printf.h"
# include "resources/libft/libft.h"

typedef struct t_stack
{
	int				index;
	int				number;
	struct t_stack	*next;
}	t_stack;

typedef struct strtol
{
	int		temp;
	int		check;
	int		num;
}	t_strtol;

typedef struct helper
{
	char	*args;
	char	**result;
	int		*tosort;
	int		total;
	int		max;
	int		moves;
	int		bitstotal;
}	t_aux;

int		add_space(t_aux *aux, char **temp_space);
void	cleantool(t_aux *aux);
int		listlen(t_stack *block);
void	max_and_digits(t_stack *block, t_aux *t_aux);
void	clean_all(t_aux *aux, t_stack *stacka, t_stack *stackb);
void	decide_algo(t_aux *aux, t_stack **stacka, t_stack **stackb);
int		prepare_sort(t_aux *aux, t_stack *stacka);
int		check_if_sorted(t_stack *stacka);
int		sort_verysmall(t_stack **t_stack, t_aux *aux);
int		parsing(int argc, char **argv, t_aux *aux);
int		join_simple(char **argv, t_aux *aux);
int		join_args(int argc, char **argv, t_aux *aux);
int		check_repeated(int num, t_aux *aux, t_strtol strtol);
void	case_four(t_stack **stacka, t_stack **stackb, t_aux *aux);
void	case_five(t_stack **stacka, t_stack **stackb, t_aux *aux);
void	sa(t_stack **stacka, t_aux *aux);
void	sb(t_stack **stackb, t_aux *aux);
void	ss(t_stack **stacka, t_stack **stackb, t_aux *aux);
void	pa(t_stack **stacka, t_stack **stackb, t_aux *aux);
void	pb(t_stack **stacka, t_stack **stackb, t_aux *aux);
void	ra(t_stack **stacka, t_aux *aux);
void	rb(t_stack **stackb, t_aux *aux);
void	rr(t_stack **stacka, t_stack **stackb, t_aux *aux);
void	rra(t_stack **stacka, t_aux *aux);
void	rrb(t_stack **stackb, t_aux *aux);
void	rrr(t_stack **stacka, t_stack **stackb, t_aux *aux);
void	ra_noprint(t_stack **stacka);
void	rb_noprint(t_stack **stackb);
void	rra_noprint(t_stack **stacka);
void	rrb_noprint(t_stack **stackb);

#endif