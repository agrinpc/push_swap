/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:27:59 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 23:28:57 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_2(int *a, int start)
{
	if (a[start] > a[start + 1])
		sa(a, start);
}

void	do_3(int *a, int start)
{
	if (a[start] > a[start + 2])
	{
		if (a[start + 1] > a[start + 2])
		{
			if (a[start] > a[start + 1])
			{
				sa(a, start);
				rra(a, start, start + 3);
			}
		}
		else
			ra(a, start, start + 3);
	}
	if (a[start] > a[start + 1])
		sa(a, start);
	if (a[start + 1] > a[start + 2])
	{
		rra(a, start, start + 3);
		do_2(a, start);
	}
}

void	do_5(int **arr, int ints[3])
{
	int	i;
	int	a_indx;
	int	a_rot;

	pb(arr, ints[S_START]);
	ints[S_START]++;
	pb(arr, ints[S_START]);
	ints[S_START]++;
	do_3(arr[ARR_A], ints[S_START]);
	i = ints[S_START];
	while (--i > -1)
	{
		a_indx = g_a_i(arr[ARR_A], arr[ARR_B][i], ints[S_START], ints[S_SIZE]);
		a_rot = return_a_r(ints, a_indx);
		sort_a(arr[ARR_A], ints, a_rot);
		pa(arr, ints[S_START] - 1);
		ints[S_START]--;
	}
	finalize_a(arr[ARR_A], ints[S_SIZE]);
}
