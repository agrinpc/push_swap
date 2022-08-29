/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:06:21 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 23:33:16 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_m(int **arr, int ints[3])
{
	int	elm;
	int	b_indx;
	int	b_rot;

	elm = get_elm(arr, ints) + ints[S_START];
	b_indx = get_b_index(arr[ARR_B], arr[ARR_A][elm], ints[S_START]);
	b_rot = return_b_r(ints[S_START], b_indx);
	pull_a_to_top(arr, ints, elm, b_rot);
	b_indx = get_b_index(arr[ARR_B],
			arr[ARR_A][ints[S_START]], ints[S_START]);
	sort_b(arr[ARR_B], ints[S_START], b_indx);
	pb(arr, ints[S_START]);
	ints[S_START]++;
}

void	do_more(int **arr, int ints[3])
{
	while (ints[S_START] < ints[S_SIZE] * 0.75 - 3)
		do_m(arr, ints);
	ints[S_WEIGHT] = ints[S_START];
	ints[S_START]--;
	while (++ints[S_START] < ints[S_SIZE] - 3)
		pb(arr, ints[S_START]);
	do_3(arr[ARR_A], ints[S_START]);
	do_rest(arr, ints);
	finalize_a(arr[ARR_A], ints[S_SIZE]);
}

void	continue_more_2(int **arr, int ints[3])
{
	ints[S_WEIGHT] = ints[S_START];
	ints[S_START]--;
	while (++ints[S_START] < ints[S_SIZE] - 3)
		pb(arr, ints[S_START]);
	do_3(arr[ARR_A], ints[S_START]);
	do_rest_2(arr, ints);
	finalize_a(arr[ARR_A], ints[S_SIZE]);
}

void	do_more_2(int **arr, int ints[3])
{
	int	i;
	int	j;
	int	ch_s;
	int	ch_e;
	int	elm;

	ch_s = 0;
	ch_e = ints[S_SIZE] / CHUNKS;
	i = -1;
	while (++i < CHUNKS - 1)
	{
		j = ch_s - 1;
		while (++j < ch_e)
		{
			elm = get_elm_in_b(arr, ints, ch_s, ch_e);
			pull_a_to_top_simple(arr, ints, elm);
			pb(arr, ints[S_START]);
			ints[S_START]++;
		}
		ch_s += ints[S_SIZE] / CHUNKS;
		ch_e += ints[S_SIZE] / CHUNKS;
	}
	continue_more_2(arr, ints);
}

void	push_swap(int *a, int size)
{
	int	ints[3];
	int	**arr;
	int	i;

	ints[S_START] = 0;
	ints[S_SIZE] = size;
	arr = make_arrays(a, size);
	if (!arr)
		return ;
	i = -1;
	while (++i < size)
		arr[ARR_A2][i] = arr[ARR_A][i];
	if (ints[S_SIZE] == 2)
		do_2(arr[ARR_A], ints[S_START]);
	else if (ints[S_SIZE] == 3)
		do_3(arr[ARR_A], ints[S_START]);
	else if (ints[S_SIZE] == 5)
		do_5(arr, ints);
	else if (ints[S_SIZE] < 201)
		do_more(arr, ints);
	else
		do_more_2(arr, ints);
	free_arrays(arr);
}
