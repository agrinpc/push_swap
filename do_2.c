/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:28:09 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 23:48:38 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rest_2(int	**arr, int ints[3])
{
	int	i;
	int	a_indx;
	int	a_rot;
	int	elm;

	i = ints[S_START];
	while (--i > -1)
	{
		elm = get_elm_in_a(arr, ints);
		a_indx = g_a_i(arr[ARR_A], arr[ARR_B][elm],
				ints[S_START], ints[S_SIZE]);
		a_rot = return_a_r(ints, a_indx);
		pull_b_to_top(arr, ints, elm, a_rot);
		a_indx = g_a_i(arr[ARR_A], arr[ARR_B][ints[S_START] - 1],
				ints[S_START], ints[S_SIZE]);
		a_rot = return_a_r(ints, a_indx);
		sort_a(arr[ARR_A], ints, a_rot);
		pa(arr, ints[S_START] - 1);
		ints[S_START]--;
	}
}

void	do_a(int **arr, int ints[3])
{
	int	a_indx;
	int	a_rot;
	int	elm;

	elm = get_elm_in_a(arr, ints) + ints[S_START] - 1;
	a_indx = g_a_i(arr[ARR_A], arr[ARR_A][elm],
			ints[S_START], ints[S_SIZE]);
	a_rot = return_a_r(ints, a_indx);
	pull_b_to_top(arr, ints, elm, a_rot);
	a_indx = g_a_i(arr[ARR_A], arr[ARR_A][ints[S_START] - 1],
			ints[S_START], ints[S_SIZE]);
	a_rot = return_a_r(ints, a_indx);
	sort_a(arr[ARR_A], ints, a_rot);
	ints[S_START]--;
	pa(arr, ints[S_START]);
}

void	do_rest(int	**arr, int ints[3])
{
	int	i;
	int	a_indx;
	int	a_rot;

	i = ints[S_START];
	while (--i > ints[S_WEIGHT])
		do_a(arr, ints);
	i++;
	while (--i > -1)
	{
		a_indx = g_a_i(arr[ARR_A], arr[ARR_B][i], ints[S_START], ints[S_SIZE]);
		a_rot = return_a_r(ints, a_indx);
		sort_a(arr[ARR_A], ints, a_rot);
		ints[S_START]--;
		pa(arr, ints[S_START]);
	}
}
