/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertogm <albertogm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:10:45 by albertogm         #+#    #+#             */
/*   Updated: 2025/08/15 19:57:14 by albertogm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *s, char c, int start)
{
	int	len;
	int	position;

	len = 0;
	position = start;
	while ((s[position]) && (s[position] != c))
	{
		len++;
		position++;
	}
	return (len);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_array(char **array, int position)
{
	while (position > 0)
		free(array[--position]);
	free(array);
}

static int	include_word(char **array, char const *s, char c)
{
	int	i;
	int	len;
	int	position;

	i = 0;
	position = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			len = word_len(s, c, i);
			array[position] = ft_substr(s, i, len);
			if (!array[position])
			{
				free_array(array, position);
				return (0);
			}
			position++;
			i = i + len;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words_total;

	if (!s)
		return (NULL);
	words_total = count_words(s, c);
	array = malloc((words_total + 1) * (sizeof(char *)));
	if (!array)
		return (NULL);
	if (!(include_word(array, s, c)))
		return (NULL);
	array[words_total] = (NULL);
	return (array);
}
