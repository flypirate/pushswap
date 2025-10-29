/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:41:24 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/13 20:52:13 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stacka, t_aux *aux)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stacka || !(*stacka)->next)
		return ;
	first = *stacka;
	second = (*stacka)->next;
	first->next = second->next;
	second->next = first;
	*stacka = second;
	aux->moves++;
	ft_printf("sa\n");
}

void	sb(t_stack **stackb, t_aux *aux)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stackb || !(*stackb)->next)
		return ;
	first = *stackb;
	second = (*stackb)->next;
	first->next = second->next;
	second->next = first;
	*stackb = second;
	aux->moves++;
	ft_printf("sb\n");
}

void	ss(t_stack **stacka, t_stack **stackb, t_aux *aux)
{
	t_stack	*first;
	t_stack	*second;

	if (*stacka && (*stacka)->next)
	{
		first = *stacka;
		second = (*stacka)->next;
		first->next = second->next;
		second->next = first;
		*stacka = second;
	}
	if (*stackb && (*stackb)->next)
	{
		first = *stackb;
		second = (*stackb)->next;
		first->next = second->next;
		second->next = first;
		*stackb = second;
	}
	aux->moves++;
	ft_printf("ss\n");
}

void	pa(t_stack **stacka, t_stack **stackb, t_aux *aux)
{
	t_stack	*topa;
	t_stack	*topb;

	if (!*stackb)
		return ;
	topa = *stacka;
	topb = *stackb;
	*stackb = topb->next;
	topb->next = topa;
	*stacka = topb;
	aux->moves++;
	ft_printf("pa\n");
}

void	pb(t_stack **stacka, t_stack **stackb, t_aux *aux)
{
	t_stack	*topa;
	t_stack	*topb;

	if (!*stacka)
		return ;
	topa = *stacka;
	topb = *stackb;
	*stacka = topa->next;
	topa->next = topb;
	*stackb = topa;
	aux->moves++;
	ft_printf("pb\n");
}
