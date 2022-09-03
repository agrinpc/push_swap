/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:30:19 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/30 17:50:10 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_elm_in_a(int **arr, int ints[3])
{
	int	max;
	int	rows;
	int	dir;

	max = 0;
	if (ints[S_START] > 1)
		rows = ints[S_START] / 2;
	else
		return (0);
	dir = get_max_a(arr, ints, rows, &max);
	if (dir == -1)
		max = ints[S_START] - max - 1;
	else
		max--;
	return (max);
}

int	return_a_r(int ints[3], int a_index)
{
	if (a_index == ints[S_SIZE] - 1)
		return (0);
	if (abs(a_index - ints[S_START]) >= abs(ints[S_SIZE] - 1 - a_index))
		return (-(ints[S_SIZE] - a_index - 1));
	else
		return ((a_index - ints[S_START] + 1));
	return (0);
}

void	finalize_a(int *a, int size)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (++i < size)
		if (a[i] > a[max])
			max = i;
	i = -1;
	if (max < size / 2)
		while (++i <= max)
			ra(a, 0, size);
	else
		while (++max < size)
			rra(a, 0, size);
}

void	pull_b_to_top(int **arr, int ints[3], int i, int a_rot)
{
	int	j;

	j = -1;
	if (i > ints[S_START] / 2)
	{
		while (++j < ints[S_START] - i - 1)
		{
			if (a_rot > 0 && j < a_rot)
				rr(arr[ARR_A], arr[ARR_B], ints[S_START], ints[S_SIZE]);
			else
				rb(arr[ARR_B], 0, ints[S_START]);
		}
	}
	else
	{
		while (++j <= i)
		{
			if (a_rot < 0 && j < -a_rot)
				rrr(arr[ARR_A], arr[ARR_B], ints[S_START], ints[S_SIZE]);
			else
				rrb(arr[ARR_B], 0, ints[S_START]);
		}
	}
}

int	get_a_position(int *a, int ints[3], int val)
{
	int	i;
	int	range;

	i = -1;
	range = ints[S_SIZE] - ints[S_START];
	while (++i < range)
		if (a[i + ints[S_START]] == val)
			break ;
	if (i > range / 2)
		return (-ints[S_SIZE] + i);
	return (i);
}
