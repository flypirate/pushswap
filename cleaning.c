/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:25:28 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/14 16:21:07 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleantool(t_aux *aux)
{
	int	i;

	i = 0;
	if (aux->args)
		free(aux->args);
	if (aux->tosort)
		free(aux->tosort);
	if (aux->result != NULL)
	{
		while (aux->result[i])
		{
			free(aux->result[i]);
			i++;
		}
		free(aux->result);
	}
	free(aux);
}

void	clean_all(t_aux *aux, t_stack *stacka, t_stack *stackb)
{
	t_stack	*temp;

	temp = stacka;
	if (aux)
		cleantool(aux);
	if (stacka)
	{
		while (stacka)
		{
			temp = stacka->next;
			free(stacka);
			stacka = temp;
		}
	}
	if (stackb)
	{
		temp = stackb;
		while (stackb)
		{
			temp = stackb->next;
			free(stackb);
			stackb = temp;
		}
	}
}
