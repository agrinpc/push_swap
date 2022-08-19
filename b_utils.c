/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:34:43 by miahmadi          #+#    #+#             */
/*   Updated: 2022/07/01 13:43:07 by miahmadi         ###   ########.fr       */
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

void sort_b(int *b, int size, int i)
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
	return (get_b_index_cmp(arr[ARR_B], val, ints[S_START]) + (i / 2 + i % 2) - get_rr_rrr(i, val, arr[ARR_B], ints[S_START]));
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
	while (++i < rows)
	{
		tmp[i * 2] = arr[ARR_A][ints[S_START] + i];
		tmp[i * 2 + 1] = arr[ARR_A][ints[S_SIZE] - i - 1];
	}
	i = 0;
	while (++i < 2 * rows)
	{
		if (get_moves_total(arr, ints, tmp, i) < get_moves_total(arr, ints, tmp, max))
			max = i;
	}
	free(tmp);
	return (get_elm_index(ints, max));
}

int	get_elm_in_b(int **arr, int	ints[3], int ch_s, int ch_e)
{
	int	i;
	int	max;
	
	i = ints[S_START] - 1;
	max = -1;
	while (++i < ints[S_SIZE] && max == -1)
		if (arr[ARR_A][i] < ch_e && arr[ARR_A][i] >= ch_s)
			max = i;
	// printf("\n** max = %d, moves = %d\n", arr[ARR_A][max], get_b_moves(arr, ints, arr[ARR_A][max]));
	i--;
	while (++i < ints[S_SIZE])
	{	
		if (arr[ARR_A][i] < ch_e && arr[ARR_A][i] >= ch_s)
			if (get_b_moves(arr, ints, arr[ARR_A][i]) < get_b_moves(arr, ints, arr[ARR_A][max]))
				max = i;
		// printf("\ni = %d, moves = %d\n", arr[ARR_A][i], get_b_moves(arr, ints, arr[ARR_A][i]));
	}
	return (max);
}

int	get_b_moves(int **arr, int ints[3], int val)
{
	int	a_rot;
	int b_rot;
	int	ret;

	b_rot = 0;
	a_rot = get_a_position(arr[ARR_A], ints, val);
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

int get_rr_rrr(int max, int val, int *b, int start)
{
	int	j;
	int	ret;
	int	tmp;
	int	i;

	i = -1;
	ret = 0;
	j = get_b_index(b, val, start);
	tmp = return_b_r(start, j);
	if (is_odd(max))
	{
		if (tmp > 0)
			while (++i < max / 2 && i < tmp)
				ret++;
	}
	else
	{
		if (tmp < 0)
		while (++i < max / 2 + 1 && i < -tmp)
				ret++;
	}
	return (ret);
}

int return_b_r(int size, int i)
{
	if (size < 2 || i == 0 || size == i)
		return (0);
	if (size - i < (size + 1) / 2)
		return (size - i);
	return (-i - 1);
}

void	finalize_b(int *b, int start)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (++i < start)
		if (b[i] > b[max])
			max = i;
	max++;
	sort_b(b, start, max);
}

void	pull_a_to_top(int **arr, int ints[3], int i, int b_rot)
{
	int	j;

	j = -1;
	if (i - ints[S_START] <= (ints[S_SIZE] - ints[S_START]) / 2)
	{
		while (++j < i - ints[S_START])
		{
			if (b_rot > 0 && j < b_rot)
				rr(arr[ARR_A], arr[ARR_B], ints[S_START], ints[S_SIZE]);
			else
				ra(arr[ARR_A], ints[S_START], ints[S_SIZE]);
		}
	}
	else
	{
		while (++j < ints[S_SIZE] - i)
		{
			if (b_rot < 0 && j < -b_rot)
				rrr(arr[ARR_A], arr[ARR_B], ints[S_START], ints[S_SIZE]);
			else
				rra(arr[ARR_A], ints[S_START], ints[S_SIZE]);
		}
	}
}

void	pull_a_to_top_simple(int **arr, int ints[3], int i)
{
	int	j;

	j = -1;
	if (i - ints[S_START] <= (ints[S_SIZE] - ints[S_START]) / 2)
	{
		while (++j < i - ints[S_START])
			ra(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	}
	else
	{
		while (++j < ints[S_SIZE] - i)
			rra(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	}
}