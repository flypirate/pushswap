/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertogm <albertogm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:47:04 by albegar2          #+#    #+#             */
/*   Updated: 2025/06/21 14:57:33 by albertogm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_list(t_list *lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	temp = lst;
	while (temp)
	{
		next = temp->next;
		del(temp->content);
		free(temp);
		temp = next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*last_node;

	new_list = NULL;
	new_node = NULL;
	last_node = NULL;
	while (lst)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			free_list(new_list, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		new_node->next = NULL;
		if (!new_list)
			new_list = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
		lst = lst->next;
	}
	return (new_list);
}
