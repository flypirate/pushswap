/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertogm <albertogm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:37:07 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/16 20:32:10 by albertogm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*fill_stack_a(t_aux *aux)
{
	int		i;
	t_stack	*first;
	t_stack	*new_node;
	t_stack	*current;

	i = 0;
	first = NULL;
	current = NULL;
	while (aux->result[i])
	{
		new_node = ft_calloc(1, sizeof(t_stack));
		if (!new_node)
			return (NULL);
		ft_strtol(aux->result[i], &new_node->number);
		new_node->next = NULL;
		if (!first)
			first = new_node;
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
	aux->total = listlen(first);
	max_and_digits(first, aux);
	return (first);
}

static int	check_numbers(t_aux *aux)
{
	t_strtol	strtol;
	int			i;

	i = 0;
	strtol.check = 0;
	while (aux->result[i])
	{
		strtol.check = ft_strtol(aux->result[i], &strtol.num);
		if (strtol.check != 0)
			return (1);
		if (check_repeated(strtol.num, aux, strtol) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_aux	*aux;

	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		return (0);
	if (argv[1][0] == '\0')
		return (write(2, "Error", 5), 1);
	aux = ft_calloc(1, sizeof(t_aux));
	if (!aux)
		return (clean_all(aux, stacka, stackb), 1);
	if (parsing(argc, argv, aux) != 0)
		return (clean_all(aux, stacka, stackb), write(2, "Error", 5), 1);
	if (check_numbers(aux) == 1)
		return (clean_all(aux, stacka, stackb), write(2, "Error", 5), 1);
	stacka = fill_stack_a(aux);
	if (!stacka)
		return (clean_all(aux, stacka, stackb), write(2, "Error", 5), 1);
	prepare_sort(aux, stacka);
	decide_algo(aux, &stacka, &stackb);
	clean_all(aux, stacka, stackb);
	return (0);
}
