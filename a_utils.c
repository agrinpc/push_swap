/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:40:49 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 22:31:19 by miahmadi         ###   ########.fr       */
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

int	get_move_res_a(int a_rot, int b_rot)
{
	int	ret;

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

int	get_moves_count_a(int **arr, int ints[3], int dir, int i)
{
	int	a_indx;
	int	a_rot;
	int	b_rot;
	int	val;

	val = 0;
	if (dir == -1)
		val = arr[ARR_B][ints[S_START] - i - 1];
	else if (dir == 1)
		val = arr[ARR_B][i - 1];
	a_indx = g_a_i(arr[ARR_A], val, ints[S_START], ints[S_SIZE]);
	a_rot = return_a_r(ints, a_indx);
	b_rot = dir * (-i);
	return (get_move_res_a(a_rot, b_rot));
}

int	get_max_a(int **arr, int ints[3], int rows, int *max)
{
	int	i;
	int	g_max;
	int	dir;

	i = 0;
	dir = -1;
	g_max = get_moves_count_a(arr, ints, dir, *max);
	while (++i < rows && g_max > 1)
	{
		if (get_moves_count_a(arr, ints, -1, i) < g_max)
		{
			*max = i;
			dir = -1;
			g_max = get_moves_count_a(arr, ints, dir, *max);
		}
		if (get_moves_count_a(arr, ints, 1, i) < g_max)
		{
			*max = i;
			dir = 1;
			g_max = get_moves_count_a(arr, ints, dir, *max);
		}
	}
	return (dir);
}
