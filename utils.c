/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:41:30 by miahmadi          #+#    #+#             */
/*   Updated: 2022/09/03 12:11:08 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	is_integer(const char *nptr)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr)
	{
		if (ft_isdigit(*nptr))
			num = num * 10 + (*nptr - 48);
		else
			return (sign * num);
		nptr++;
	}
	num = sign * num;
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

void	free_numbers(char **numbers, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(numbers[i]);
	free(numbers);
}

int	has_space(char *str)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (str[++i])
		if (str[i] == ' ')
				size++;
	return (size);
}