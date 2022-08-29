/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:37:38 by miahmadi          #+#    #+#             */
/*   Updated: 2022/07/01 13:43:11 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b2(int *b, int size, int i)
{
	int	j;

	if (size < 2)
		return ;
	if (i > 0)
	{
		j = -1;
		if (size - i < size / 2)
			while (++j < size - i)
				frb(b, 0, size);
		else
			while (++j < i)
				frrb(b, 0, size);
	}
}

int	g_m_c_b2(int **arr, int ints[3], int val, int i)
{
	return (get_b_index_cmp(arr[ARR_B2], val, ints[S_START])
		+ (i / 2 + i % 2) - get_rr_rrr(i, val, arr[ARR_B2], ints[S_START]));
}

void	pull_a2_to_top(int **arr, int ints[3], int i, int b_rot)
{
	int	j;

	j = -1;
	if (i - ints[S_START] <= (ints[S_SIZE] - ints[S_START]) / 2)
	{
		while (++j < i - ints[S_START])
		{
			if (b_rot > 0 && j < b_rot)
				frr(arr[ARR_A2], arr[ARR_B2], ints[S_START], ints[S_SIZE]);
			else
				fra(arr[ARR_A2], ints[S_START], ints[S_SIZE]);
		}
	}
	else
	{
		while (++j < ints[S_SIZE] - i)
		{
			if (b_rot < 0 && j < -b_rot)
				frrr(arr[ARR_A2], arr[ARR_B2], ints[S_START], ints[S_SIZE]);
			else
				frra(arr[ARR_A2], ints[S_START], ints[S_SIZE]);
		}
	}
}
