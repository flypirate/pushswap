/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:48:49 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/14 16:03:57 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	make_intarray(t_aux *aux)
{
	int	i;
	int	check;

	i = 0;
	aux->tosort = malloc(sizeof(int) * aux->total);
	if (!aux->tosort)
		return (1);
	while (i < aux->total)
	{
		check = ft_strtol(aux->result[i], &aux->tosort[i]);
		if (check == 1)
			return (1);
		i++;
	}
	return (0);
}

static void	exchange(int *arr, int l, int h)
{
	int	temp;

	temp = arr[l];
	arr[l] = arr[h];
	arr[h] = temp;
}

static void	sort_index(t_aux *aux, int low, int high)
{
	int	*arr;
	int	pivot;
	int	left;
	int	right;

	if (low >= high)
		return ;
	arr = aux->tosort;
	pivot = low;
	left = low + 1;
	right = high;
	while (left <= right)
	{
		while (left <= right && arr[left] <= arr[pivot])
			left++;
		while (left <= right && arr[right] > arr[pivot])
			right--;
		if (left < right)
			exchange(arr, left, right);
	}
	exchange(arr, low, right);
	sort_index(aux, low, right - 1);
	sort_index(aux, right + 1, high);
}

static int	add_index(t_aux *aux, t_stack *stacka)
{
	int		i;

	while (stacka)
	{
		i = 0;
		while (i < aux->total)
		{
			if (stacka->number == aux->tosort[i])
			{
				stacka->index = i;
				break ;
			}
			else
				i++;
		}
		stacka = stacka->next;
	}
	return (0);
}

int	prepare_sort(t_aux *aux, t_stack *stacka)
{
	if (make_intarray(aux) != 0)
		return (1);
	sort_index(aux, 0, aux->total - 1);
	add_index(aux, stacka);
	return (0);
}
