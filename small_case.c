/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:36:47 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/14 16:07:37 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_three(t_stack **stack, t_aux *aux)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->index;
	mid = (*stack)->next->index;
	bot = (*stack)->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(stack, aux);
	else if (top > mid && mid > bot)
	{
		sa(stack, aux);
		rra(stack, aux);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(stack, aux);
	else if (mid > top && mid > bot && top < bot)
	{
		sa(stack, aux);
		ra(stack, aux);
	}
	else if (top < mid && bot < mid && top > bot)
		rra(stack, aux);
}

static void	mins(t_stack **stacka, t_stack **stackb, t_aux *aux, int x)
{
	int		min_pos;
	t_stack	*temp;

	temp = *stacka;
	min_pos = 0;
	while (temp)
	{
		if (temp->index == x)
			break ;
		temp = temp->next;
		min_pos++;
	}
	if (min_pos >= listlen(*stacka) / 2)
	{
		while ((*stacka)->index != x)
			rra(stacka, aux);
	}
	else
	{
		while ((*stacka)->index != x)
			ra(stacka, aux);
	}
	pb(stacka, stackb, aux);
}

void	case_four(t_stack **stacka, t_stack **stackb, t_aux *aux)
{
	t_stack	*temp;
	int		min_pos;

	temp = *stacka;
	min_pos = 0;
	while (temp)
	{
		if (temp->index == 0)
			break ;
		temp = temp->next;
		min_pos++;
	}
	if (min_pos == 1)
		sa(stacka, aux);
	else if (min_pos == 2)
	{
		rra(stacka, aux);
		rra(stacka, aux);
	}
	else if (min_pos == 3)
		rra(stacka, aux);
	pb(stacka, stackb, aux);
	case_three(stacka, aux);
	pa(stacka, stackb, aux);
}

void	case_five(t_stack **stacka, t_stack **stackb, t_aux *aux)
{
	mins(stacka, stackb, aux, 0);
	mins(stacka, stackb, aux, 1);
	case_three(stacka, aux);
	pa(stacka, stackb, aux);
	pa(stacka, stackb, aux);
}

int	sort_verysmall(t_stack **stack, t_aux *aux)
{
	int	size;

	size = listlen(*stack);
	if (size == 2)
		sa(stack, aux);
	if (size == 3)
		case_three(stack, aux);
	return (0);
}
