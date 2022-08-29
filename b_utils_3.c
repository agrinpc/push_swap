/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:37:23 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 22:39:13 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
