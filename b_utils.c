/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:34:43 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/30 16:54:06 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_b_index(int *b, int val, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (val > b[i])
			if (val < b[i + 1] || b[i + 1] < b[i])
				return (i + 1);
		if (val < b[i + 1] && b[i + 1] < b[i])
			return (i + 1);
	}
	return (size);
}

int	get_b_index_cmp(int *b, int val, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (val > b[i])
		{
			if (val < b[i + 1] || b[i + 1] < b[i])
			{
				if (i + 1 < size / 2)
					return (i + 1);
				return (size - i - 1);
			}
		}
		if (val < b[i + 1] && b[i + 1] < b[i])
		{
			if (i + 1 < size / 2)
				return (i + 1);
			return (size - i - 1);
		}
	}
	return (0);
}

void	sort_b(int *b, int size, int i)
{
	int	j;

	if (size < 2)
		return ;
	if (i > 0)
	{
		j = -1;
		if (size - i < size / 2)
			while (++j < size - i)
				rb(b, 0, size);
		else
			while (++j < i)
				rrb(b, 0, size);
	}
}

int	get_moves_count_b(int **arr, int ints[3], int val, int i)
{
	return (get_b_index_cmp(arr[ARR_B], val, ints[S_START])
		+ (i / 2 + i % 2) - get_rr_rrr(i, val, arr[ARR_B], ints[S_START]));
}

int	get_elm(int **arr, int ints[3])
{
	int	*tmp;
	int	i;
	int	max;
	int	rows;

	i = -1;
	max = 0;
	if (ints[S_SIZE] - ints[S_START] > 2)
		rows = get_rows(ints[S_SIZE] - ints[S_START]);
	else
		return (ints[S_SIZE] - ints[S_START] - 1);
	tmp = malloc(2 * sizeof(int) * rows);
	if (!tmp)
		return (-1);
	while (++i < rows)
	{
		tmp[i * 2] = arr[ARR_A][ints[S_START] + i];
		tmp[i * 2 + 1] = arr[ARR_A][ints[S_SIZE] - i - 1];
	}
	i = 0;
	while (++i < 2 * rows)
		if (get_moves_t(arr, ints, tmp, i) < get_moves_t(arr, ints, tmp, max))
			max = i;
	free(tmp);
	return (get_elm_index(ints, max));
}
