/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:46:04 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/30 00:17:53 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**make_arrays(int *a, int size)
{
	int	*b;
	int	*c;
	int	*d;
	int	**arr;

	b = malloc(size * sizeof(int));
	if (!b)
		return (free_b(a));
	c = malloc(size * sizeof(int));
	if (!c)
		return (free_c(a, b));
	d = malloc(size * sizeof(int));
	if (!d)
		return (free_d(a, b, c));
	arr = malloc(4 * sizeof(char *));
	if (!arr)
		free_all(a, b, c, d);
	arr[ARR_A] = a;
	arr[ARR_B] = b;
	arr[ARR_A2] = c;
	arr[ARR_B2] = d;
	return (arr);
}

int	**make_arrays_bonus(int *a, int size)
{
	int	*b;
	int	**arr;

	b = malloc(size * sizeof(int));
	if (!b)
	{
		free(a);
		return (NULL);
	}
	arr = malloc(2 * sizeof(char *));
	if (!arr)
	{
		free(a);
		free(b);
		return (NULL);
	}
	arr[ARR_A] = a;
	arr[ARR_B] = b;
	return (arr);
}

void	free_arrays(int **arr)
{
	free(arr[ARR_A]);
	free(arr[ARR_B]);
	free(arr[ARR_A2]);
	free(arr[ARR_B2]);
	free(arr);
}

void	free_arrays_bonus(int **arr)
{
	free(arr[ARR_A]);
	free(arr[ARR_B]);
	free(arr);
}

int	validate_numbers(int *a, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (a[i] == a[j])
				return (0);
	}
	return (1);
}
