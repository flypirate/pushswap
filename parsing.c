/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertogm <albertogm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:37:13 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/19 14:27:21 by albertogm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int argc, char **argv, t_aux *aux)
{
	if (argc == 2)
	{
		if (join_simple(argv, aux) != 0)
			return (1);
	}
	else
	{
		join_args(argc, argv, aux);
		aux->result = ft_split(aux->args, ' ');
		if (!aux->result)
			return (1);
	}
	return (0);
}

int	join_simple(char **argv, t_aux *aux)
{
	aux->result = ft_split(argv[1], ' ');
	if (!aux->result)
		return (1);
	if (aux->result[0] == NULL)
		return (1);
	return (0);
}

int	join_args(int argc, char **argv, t_aux *aux)
{
	int		i;
	char	*temp_add;
	char	*temp_space;

	i = 1;
	temp_space = NULL;
	aux->args = ft_strdup("");
	if (!aux->args)
		return (1);
	while (i < argc)
	{
		temp_add = ft_strjoin(aux->args, argv[i]);
		if (!temp_add)
			return (free(aux->args), 1);
		free(aux->args);
		aux->args = temp_add;
		if (i < argc - 1)
		{
			if (add_space(aux, &temp_space) != 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_repeated(int num, t_aux *aux, t_strtol strtol)
{
	int	times;
	int	i;

	times = 0;
	i = 0;
	while (aux->result[i])
	{
		ft_strtol(aux->result[i], &strtol.temp);
		if (num == strtol.temp)
			times++;
		i++;
	}
	if (times > 1)
		return (1);
	return (0);
}
