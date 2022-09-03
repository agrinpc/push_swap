/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:44:01 by miahmadi          #+#    #+#             */
/*   Updated: 2022/09/03 12:20:33 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char *str)
{
	int		i;
	int		size;
	char	last;

	i = 0;
	size = 0;
	while (str[i] == ' ')
		i++;
	if (str[i])
	{
		last = str[i];
		size++;
		i++;
	}
	while (str[i])
	{
		if (str[i] == ' ')
			if (last != ' ')
				size++;
		last = str[i];
		i++;
	}
	if (str[i - 1] == ' ')
		size--;
	return (size);
}

int	check_if_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
		{
			if (str[i] == '-')
			{
				if (str[i - 1])
				{
					if (!str[i + 1])
						return (error("Minus sign is used in a wong way"));
					if (str[i - 1] != ' ')
						return (error("Minus sign is used in a wong way"));
					if (str[i + 1] < '0' || str[i + 1] > '9')
						return (error("Minus sign is used in a wong way"));
				}
			}
			else
				return (error("There is a non-digit value among arguments"));
		}
	}
	return (1);
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

int	*get_args(char **argv, int size, int input)
{
	int		*res;

	if (input == 2)
	{
		if (!check_if_digit(argv[1]))
			return (0);
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
		if (has_space(argv[i]) > 0)
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
