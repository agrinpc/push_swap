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

int	g_a_i(int *a, int val, int start, int size)
{
	int	i;

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

void	sort_a(int *a, int ints[3], int a_rot)
{
	int	j;

	if (ints[S_SIZE] - ints[S_START] < 2)
		return ;
	j = -1;
	if (a_rot > 0)
		while (++j < a_rot)
			ra(a, ints[S_START], ints[S_SIZE]);
	else
		while (++j < -a_rot)
			rra(a, ints[S_START], ints[S_SIZE]);
}

int	get_moves_count_a(int **arr, int ints[3], int dir, int i)
{
	int	a_indx;
	int	a_rot;
	int	b_rot;
	int	ret;
	int	val;

	val = 0;
	if (dir == -1)
		val = arr[ARR_B][ints[S_START] - i - 1];
	else if (dir == 1)
		val = arr[ARR_B][i - 1];
	a_indx = g_a_i(arr[ARR_A], val, ints[S_START], ints[S_SIZE]);
	a_rot = return_a_r(ints, a_indx);
	b_rot = dir * (-i);
	if (a_rot < 0 && b_rot < 0)
	{
		if (a_rot < b_rot)
			return (-a_rot);
		else
			return (-b_rot);
	}
	if (a_rot > 0 && b_rot > 0)
	{
		if (a_rot > b_rot)
			return (a_rot);
		else
			return (b_rot);
	}
	ret = a_rot - b_rot;
	if (ret < 0)
		ret = -1 * ret;
	return (ret);
}

int	get_elm_in_a(int **arr, int ints[3])
{
	int	i;
	int	max;
	int	g_max;
	int	rows;
	int	dir;

	max = 0;
	if (ints[S_START] > 1)
		rows = ints[S_START] / 2;
	else
		return (0);
	i = 0;
	dir = -1;
	g_max = get_moves_count_a(arr, ints, dir, max);
	while (++i < rows)
	{
		if (g_max < 2)
			break ;
		if (get_moves_count_a(arr, ints, -1, i) < g_max)
		{
			max = i;
			dir = -1;
			g_max = get_moves_count_a(arr, ints, dir, max);
		}
		if (get_moves_count_a(arr, ints, 1, i) < g_max)
		{
			max = i;
			dir = 1;
			g_max = get_moves_count_a(arr, ints, dir, max);
		}
	}
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
