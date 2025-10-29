/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:27:13 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/13 18:26:12 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stacka, t_aux *aux)
{
	t_stack	*first;
	t_stack	*end;

	if (!*stacka || !(*stacka)->next)
		return ;
	first = *stacka;
	end = *stacka;
	*stacka = (*stacka)->next;
	while (end->next)
		end = end->next;
	end->next = first;
	first->next = NULL;
	aux->moves++;
	ft_printf("ra\n");
}

void	rb(t_stack **stackb, t_aux *aux)
{
	t_stack	*first;
	t_stack	*end;

	if (!*stackb || !(*stackb)->next)
		return ;
	first = *stackb;
	end = *stackb;
	*stackb = (*stackb)->next;
	while (end->next)
		end = end->next;
	end->next = first;
	first->next = NULL;
	aux->moves++;
	ft_printf("rb\n");
}

void	ra_noprint(t_stack **stacka)
{
	t_stack	*first;
	t_stack	*end;

	if (!*stacka || !(*stacka)->next)
		return ;
	first = *stacka;
	end = *stacka;
	*stacka = (*stacka)->next;
	while (end->next)
		end = end->next;
	end->next = first;
	first->next = NULL;
}

void	rb_noprint(t_stack **stackb)
{
	t_stack	*first;
	t_stack	*end;

	if (!*stackb || !(*stackb)->next)
		return ;
	first = *stackb;
	end = *stackb;
	*stackb = (*stackb)->next;
	while (end->next)
		end = end->next;
	end->next = first;
	first->next = NULL;
}

void	rr(t_stack **stacka, t_stack **stackb, t_aux *aux)
{
	ra_noprint(stacka);
	rb_noprint(stackb);
	aux->moves++;
	ft_printf("rr\n");
}
