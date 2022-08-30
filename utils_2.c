/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:44:01 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/30 15:20:07 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_space(char *str)
{
	int	i;
	int	size;

	i = -1;
	size = 1;
	while (str[++i])
		if (str[i] == ' ')
			size++;
	return (size);
}

int	*pre_order(int *a, int size)
{
	int	i;
	int	j;
	int	val;
	int	*c;

	c = malloc(size * sizeof(int));
	if (!c)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		j = -1;
		val = 0;
		while (++j < size)
			if (a[j] > a[i])
				val++;
		c[i] = size - 1 - val;
	}
	free(a);
	return (c);
}

char	**get_numbers(char *str)
{
	int		i;
	char	**numbers;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
		{
			error("There is a non-digit value among arguments");
			return (NULL);
		}
	}
	numbers = ft_split(str, ' ');
	return (numbers);
}

int	*get_args(char **argv, int size, int input)
{
	int		*res;

	if (input == 2)
	{
		res = get_args_2(argv, size);
		if (!res)
			return (free_arr(res));
	}
	else
	{
		res = get_args_1(argv, size);
		if (!res)
			return (free_arr(res));
	}
	return (res);
}

int	check_input(char **argv, int argc)
{
	int	i;
	int	spc;

	i = 0;
	spc = 0;
	while (++i < argc)
	{
		if (has_space(argv[i]) > 1)
		{
			if (argc > 2)
				return (0);
			spc++;
		}
	}
	if (spc == 0)
		return (1);
	return (2);
}
