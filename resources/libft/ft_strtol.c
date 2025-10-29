/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertogm <albertogm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:13:51 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/14 00:46:43 by albertogm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strtol(const char *nptr, int *num)
{
	long	number;
	long	i;
	long	sign;

	i = 0;
	sign = 1;
	number = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	if (nptr[i] == '\0')
		return (1);
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		number = (number * 10) + (nptr[i++] - '0');
		if (number * sign > 2147483647 || number * sign < -2147483648)
			return (1);
	}
	if (nptr[i] != '\0' && (nptr[i] < 48 || nptr[i] > 57))
		return (1);
	return (*num = number * sign, 0);
}
