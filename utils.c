/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:07:31 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/14 15:54:47 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	listlen(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	add_space(t_aux *aux, char **temp_space)
{
	*temp_space = ft_strjoin(aux->args, " ");
	if (!(*temp_space))
		return (free(aux->args), 1);
	free(aux->args);
	aux->args = *temp_space;
	return (0);
}

static int	bits_total(int number)
{
	int	temp;
	int	i;

	temp = number;
	i = 0;
	if (temp == 0)
		return (1);
	while (temp > 0)
	{
		temp = temp >> 1;
		i++;
	}
	return (i);
}

void	max_and_digits(t_stack *stack, t_aux *aux)
{
	int	max;

	max = stack->number;
	while (stack)
	{
		if (stack->number > max)
			max = stack->number;
		stack = stack->next;
	}
	aux->max = max;
	aux->moves = 0;
	aux->bitstotal = bits_total(aux->total - 1);
}

int	check_if_sorted(t_stack *stacka)
{
	t_stack	*next;

	next = stacka->next;
	while (stacka && stacka->next)
	{
		if (stacka->index > next->index)
			return (1);
		else
		{
			stacka = stacka->next;
			next = next->next;
		}
	}
	return (0);
}
