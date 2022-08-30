/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:04:05 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/30 16:54:19 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves_min_b(int **arr, int ints[3], int *tmp)
{
	int	rows;
	int	*t2;
	int	j;
	int	min;

	rows = get_rows(ints[S_SIZE] - ints[S_START]);
	t2 = malloc(2 * sizeof(int) * rows);
	if (!t2)
		return (-1);
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
	free(t2);
	return (min);
}

int	get_moves_t(int **arr, int ints[3], int *tmp, int i)
{
	int	min;
	int	moves;
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
	min = get_moves_min_b(arr, ints, tmp);
	ints[S_START]--;
	return (moves + g_m_c_b2(arr, ints, tmp[min], min));
}
