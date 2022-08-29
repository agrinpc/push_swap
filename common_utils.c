/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:39:04 by miahmadi          #+#    #+#             */
/*   Updated: 2022/07/01 13:49:08 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cpy_arr(int *src, int *dst, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		dst[i] = src[i];
	}
}

int	get_rows(int size)
{
	if (size < 5)
		return (1);
	if (size < 13)
		return (2);
	if (size < 101)
		return (6);
	if (size < 301)
		return (11);
	if (size < 501)
		return (16);
	return (20);
}

int	abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int	is_odd(int num)
{
	if (num % 2 == 0)
		return (1);
	return (0);
}

int	get_elm_index(int ints[3], int max)
{
	if (is_odd(max))
		return (max / 2);
	return (ints[S_SIZE] - ints[S_START] - 1 - (max / 2));
}

int	get_moves_t(int **arr, int ints[3], int *tmp, int i)
{
	int	rows;
	int	min;
	int	moves;
	int	*t2;
	int	j;
	int	elm;
	int	b_indx;
	int	b_rot;

	cpy_arr(arr[ARR_A], arr[ARR_A2], ints[S_SIZE]);
	cpy_arr(arr[ARR_B], arr[ARR_B2], ints[S_START]);
	moves = g_m_c_b2(arr, ints, tmp[i], i);
	elm = get_elm_index(ints, i);
	b_indx = get_b_index(arr[ARR_B2], arr[ARR_A2][elm], ints[S_START]);
	b_rot = return_b_r(ints[S_START], b_indx);
	pull_a2_to_top(arr, ints, elm, b_rot);
	b_indx = get_b_index(arr[ARR_B2],
			arr[ARR_A2][ints[S_START]], ints[S_START]);
	sort_b2(arr[ARR_B2], ints[S_START], b_indx);
	fpb(arr, ints[S_START]);
	ints[S_START]++;
	rows = get_rows(ints[S_SIZE] - ints[S_START]);
	t2 = malloc(2 * sizeof(int) * rows);
	j = -1;
	while (++j < rows)
	{
		t2[j * 2] = arr[ARR_A2][ints[S_START] + j];
		t2[j * 2 + 1] = arr[ARR_A2][ints[S_SIZE] - j - 1];
	}
	j = 0;
	min = 0;
	while (++j < 2 * rows)
		if (g_m_c_b2(arr, ints, t2[j], j) < g_m_c_b2(arr, ints, tmp[min], min))
			min = j;
	ints[S_START]--;
	return (moves + g_m_c_b2(arr, ints, tmp[min], min));
}
