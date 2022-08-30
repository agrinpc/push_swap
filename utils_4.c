/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:28:23 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/30 17:05:53 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_number(char **argv, int size)
{
	int	i;
	int	j;

	i = 0;
	while (++i < size)
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
			{
				error("There is a non-digit value among arguments");
				return (0);
			}
		}
	}
	return (1);
}

int	*get_args_2(char **argv, int size)
{
	int		*res;
	int		i;
	char	**numbers;

	res = malloc((size) * sizeof(int));
	if (!res)
		return (NULL);
	numbers = get_numbers(argv[1]);
	i = -1;
	if (!numbers)
		return (free_arr(res));
	while (++i < size)
	{
		if (!is_integer(numbers[i]))
		{
			error("Argument is not in integer range");
			free(numbers);
			return (free_arr(res));
		}
		res[i] = ft_atoi(numbers[i]);
	}
	free_numbers(numbers, size);
	return (res);
}

int	*get_args_1(char **argv, int size)
{
	int	*res;
	int	i;

	res = malloc((size) * sizeof(int));
	if (!res)
		return (NULL);
	if (!check_if_number(argv, size + 1))
		return (free_arr(res));
	i = -1;
	while (++i < size)
	{
		if (!is_integer(argv[i + 1]))
		{
			error("Argument is not in integer range");
			return (free_arr(res));
		}
		res[i] = ft_atoi(argv[i + 1]);
	}
	return (res);
}
