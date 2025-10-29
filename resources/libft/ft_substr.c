/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:21:20 by albegar2          #+#    #+#             */
/*   Updated: 2025/04/24 23:02:39 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*start_error(void)
{
	char	*substring;

	substring = malloc(sizeof(char));
	if (!substring)
		return (NULL);
	substring[0] = '\0';
	return (substring);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	sub_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (start_error());
	sub_len = ft_strlen(s + start);
	if (sub_len > len)
		sub_len = len;
	substring = malloc((sub_len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		substring[i] = s[start];
		start++;
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
