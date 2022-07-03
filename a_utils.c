/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:40:49 by miahmadi          #+#    #+#             */
/*   Updated: 2022/07/02 13:12:55 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_a_index(int *a, int val, int start, int size)
{
	int	i;

	// if (val == 15)
	// printf("\n*** val = %d, start = %d, size = %d ***\n", val, start, size);
	i = start - 1;
	while (++i < size - 1)
	{
		if (val > a[i])
			if (val < a[i + 1] || a[i + 1] < a[i])
				return (i);
		if (val < a[i + 1] && a[i + 1] < a[i])
			return (i);
	}
	return (size - 1);
}

void sort_a(int *a, int ints[3], int a_rot)
{
	int	j;

	if (ints[S_SIZE] - ints[S_START] < 2)
		return ;
	j = -1;
	if (a_rot > 0)
		while (++j < a_rot)
			rra(a, ints[S_START], ints[S_SIZE]);
	else
		while (++j < -a_rot)
			ra(a, ints[S_START], ints[S_SIZE]);
}

int	get_moves_count_a(int **arr, int ints[3], int dir, int i)
{
	int	a_indx;
	int a_rot;
	int	b_rot;
	int	ret;
	int	val;

	if (dir == -1)
		val = arr[ARR_B][ints[S_START] - i];
	else if (dir == 1)
		val = arr[ARR_B][i - 1];
	a_indx = get_a_index(arr[ARR_A], val, ints[S_SIZE], ints[S_SIZE]);
	a_rot = return_a_r(ints, a_indx);
	b_rot = i;
	if ((a_rot < 0 && dir == -1) || (a_rot > 0 && dir == 1))
		b_rot = i - dir * a_rot;
	if (b_rot < 0)
		b_rot = 0;
	// printf("\n a_rot = %d, b_rot = %d, dir = %d, res = %d\n", a_rot, b_rot, dir, b_rot + dir * a_rot);
	ret = b_rot + dir * a_rot;
	return (ret);
}

int	get_elm_in_a(int **arr, int ints[3])
{
	int	i;
	int	max;
	int	rows;
	int	dir;

	max = 0;
	if (ints[S_START] > 1)
		rows = ints[S_START] / 2;
	else
		return (0);
	i = 0;
	dir = -1;
	// printf("\n1 - maxmove = %d", get_moves_count_a(arr, ints, dir, max));
	while (++i < rows)
	{
		
		if (get_moves_count_a(arr, ints, -1, i) < get_moves_count_a(arr, ints, dir, max))
		{
			max = i;
			dir = -1;
		}
		if (get_moves_count_a(arr, ints, 1, i) < get_moves_count_a(arr, ints, dir, max))
		{
			max = i;
			dir = 1;
		}
	}
	if (dir == -1)
		max = ints[S_START] - max - 1;
	else
		max--;
	// printf("\n*** max = %d ***\n", max);
	return (max);
}

int return_a_r(int ints[3], int a_index)
{
	// printf("\n*** size = %d, start = %d, a_index = %d ***\n", ints[S_SIZE], ints[S_START], a_index);
	if (a_index == ints[S_SIZE] - 1)
		return (0);
	if (abs(a_index - ints[S_START]) > abs(ints[S_SIZE] - 1 - a_index))
		return (ints[S_SIZE] - a_index - 1);
	else
		return (ints[S_START] - a_index - 1);
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
	// printf("\n ** max = %d\n", max);
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
	// printf("\n*** start = %d, i = %d, a_rot = %d ***\n", ints[S_START], i, a_rot);
	while (++j < i - ints[S_START])
	{
		if (a_rot > 0 && j < a_rot)
			rr(arr[ARR_A], arr[ARR_B], ints[S_START], ints[S_SIZE]);
		else
			rb(arr[ARR_B], ints[S_START], ints[S_SIZE]);
	}
}