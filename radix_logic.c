/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:36:55 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/14 17:29:40 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort(t_stack **stacka, t_stack **stackb, t_aux *aux)
{
	int	size;
	int	bits;

	bits = 0;
	while (bits < aux->bitstotal)
	{
		size = listlen(*stacka);
		while ((*stacka) && size)
		{
			if ((((*stacka)->index >> bits) & 1) == 0)
				pb(stacka, stackb, aux);
			else
				ra(stacka, aux);
			size--;
		}
		while ((*stackb))
			pa(stacka, stackb, aux);
		bits++;
	}
	while (*stackb)
		pa(stacka, stackb, aux);
}

void	decide_algo(t_aux *aux, t_stack **stacka, t_stack **stackb)
{
	int	size;

	size = aux->total;
	if (check_if_sorted(*stacka) == 0)
		return ;
	if (size > 0 && size <= 3)
		sort_verysmall(stacka, aux);
	if (size == 4)
		case_four(stacka, stackb, aux);
	if (size == 5)
		case_five(stacka, stackb, aux);
	if (size > 5)
		radix_sort(stacka, stackb, aux);
}
