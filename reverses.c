/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:27:31 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/13 18:25:42 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stacka, t_aux *aux)
{
	t_stack	*previous;
	t_stack	*first;
	t_stack	*current;

	if (!*stacka || !(*stacka)->next)
		return ;
	previous = *stacka;
	first = *stacka;
	current = (*stacka)->next;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = first;
	*stacka = current;
	aux->moves++;
	ft_printf("rra\n");
}

void	rrb(t_stack **stackb, t_aux *aux)
{
	t_stack	*previous;
	t_stack	*first;
	t_stack	*current;

	if (!*stackb || !(*stackb)->next)
		return ;
	previous = *stackb;
	first = *stackb;
	current = (*stackb)->next;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = first;
	*stackb = current;
	aux->moves++;
	ft_printf("rrb\n");
}

void	rra_noprint(t_stack **stacka)
{
	t_stack	*previous;
	t_stack	*first;
	t_stack	*current;

	if (!*stacka || !(*stacka)->next)
		return ;
	previous = *stacka;
	first = *stacka;
	current = (*stacka)->next;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = first;
	*stacka = current;
}

void	rrb_noprint(t_stack **stackb)
{
	t_stack	*previous;
	t_stack	*first;
	t_stack	*current;

	if (!*stackb || !(*stackb)->next)
		return ;
	previous = *stackb;
	first = *stackb;
	current = (*stackb)->next;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = first;
	*stackb = current;
}

void	rrr(t_stack **stacka, t_stack **stackb, t_aux *aux)
{
	rra_noprint(stacka);
	rrb_noprint(stackb);
	aux->moves++;
	ft_printf("rrr\n");
}
