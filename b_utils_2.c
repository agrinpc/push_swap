/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:37:23 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 22:39:36 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_elm_in_b(int **arr, int ints[3], int ch_s, int ch_e)
{
	int	i;
	int	max;
	int	max_moves;

	i = ints[S_START] - 1;
	max = -1;
	while (++i < ints[S_SIZE] && max == -1)
		if (arr[ARR_A][i] < ch_e && arr[ARR_A][i] >= ch_s)
			max = i;
	max_moves = get_b_moves(arr, ints, arr[ARR_A][max]);
	i--;
	while (++i < ints[S_SIZE])
	{
		if (arr[ARR_A][i] < ch_e && arr[ARR_A][i] >= ch_s)
		{
			if (get_b_moves(arr, ints, arr[ARR_A][i]) < max_moves)
			{
				max = i;
				max_moves = get_b_moves(arr, ints, arr[ARR_A][max]);
				if (max_moves < 2)
					break ;
			}
		}
	}
	return (max);
}

int	get_b_moves(int **arr, int ints[3], int val)
{
	int	a_rot;
	int	ret;

	a_rot = get_a_position(arr[ARR_A], ints, val);
	ret = a_rot;
	if (ret < 0)
		ret = -1 * ret;
	return (ret);
}

int	get_rr_rrr(int max, int val, int *b, int start)
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
		if (tmp < 0)
			while (++i < max / 2 + 1 && i < -tmp)
				ret++;
	return (ret);
}

int	return_b_r(int size, int i)
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
