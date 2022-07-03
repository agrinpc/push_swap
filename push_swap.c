/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:06:21 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/25 16:19:26 by miahmadi         ###   ########.fr       */
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
		ra(a, start, start + 3);
		if (a[start] > a[start + 2])
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

void	do_rest(int	**arr, int ints[3])
{
	int	i;
	int	a_indx;
	int	a_rot;
	int	elm;
	// printf("\n A:\n");
	// print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	// printf("\n B:\n");
	// print_a(arr[ARR_B], 0, ints[S_START]);
	i = ints[S_START];
	while (--i > -1)
	{
		elm = get_elm_in_a(arr, ints);
		// printf("\n *** elm = %d v *** \n", elm);
		a_indx = get_a_index(arr[ARR_A], arr[ARR_B][elm], ints[S_START], ints[S_SIZE]);
		a_rot = return_a_r(ints, a_indx);
		// printf("\n*** size = %d, start = %d, a_rot = %d, elm = %d, a_index = %d ****\n", ints[S_SIZE], ints[S_START], a_rot, arr[ARR_B][elm], a_indx);
		pull_b_to_top(arr, ints, elm, a_rot);
		a_indx = get_a_index(arr[ARR_A], arr[ARR_B][elm], ints[S_START], ints[S_SIZE]);
		a_rot = return_a_r(ints, a_indx);
		// printf("\n*** size = %d, start = %d, a_rot = %d, elm = %d, a_index = %d ****\n", ints[S_SIZE], ints[S_START], a_rot, arr[ARR_B][elm], a_indx);
		sort_a(arr[ARR_A], ints, a_rot);
		pa(arr, ints[S_START] - 1);
		ints[S_START]--;
		// printf("\nBBBBBBBBBB:\n");
		// print_a(arr[ARR_B], 0, ints[S_START]);
		// printf("\nAAAAAAAAAA:\n");
		// print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	}
	// while (--i > ints[S_WEIGHT])
	// {
	// 	// print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	// 	elm = get_elm_in_a(arr, ints) + ints[S_START] - 1;
	// 	a_indx = get_a_index(arr[ARR_A], arr[ARR_A][elm], ints[S_START], ints[S_SIZE]);
	// 	a_rot = return_a_r(ints, a_indx);
	// 		// printf("\n*** size = %d, start = %d, a_rot = %d, elm = %d, a_index = %d ****\n", ints[S_SIZE], ints[S_START], a_rot, arr[ARR_B][elm], a_indx);
	// 	pull_b_to_top(arr, ints, elm, a_rot);
	// 	a_indx = get_a_index(arr[ARR_A], arr[ARR_A][elm], ints[S_START], ints[S_SIZE]);
	// 	a_rot = return_a_r(ints, a_indx);
	// 	sort_a(arr[ARR_A], ints, a_rot);
	// 	// print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	// 	pa(arr, ints[S_SIZE]);
	// 	ints[S_START]--;
	// 	print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	// }
	// i++;
	// while (--i > -1)
	// {
	// 	a_indx = get_a_index(arr[ARR_A], arr[ARR_B][i], ints[S_START], ints[S_SIZE]);
	// 	a_rot = return_a_r(ints, a_indx);
	// 	if (arr[ARR_B][i] == 8)
	// 		printf("\n*** size = %d, start = %d, a_rot = %d, elm = %d, a_index = %d ****\n", ints[S_SIZE], ints[S_START], a_rot, arr[ARR_B][i], a_indx);
	// 	sort_a(arr[ARR_A], ints, a_rot);
	// 	pa(arr, ints[S_SIZE]);
	// 	ints[S_START]--;
	// 	print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	// }
}

void	do_more(int **arr, int ints[3])
{
	int	elm;
	int b_indx;
	int	b_rot;

	while (ints[S_START] < ints[S_SIZE] * 0.86 - 3)
	{
		elm = get_elm(arr, ints) + ints[S_START];
		b_indx = get_b_index(arr[ARR_B], arr[ARR_A][elm], ints[S_START]);
		b_rot = return_b_r(ints[S_START], b_indx);
		pull_a_to_top(arr, ints, elm, b_rot);
		b_indx = get_b_index(arr[ARR_B], arr[ARR_A][ints[S_START]], ints[S_START]);
		sort_b(arr[ARR_B], ints[S_START], b_indx);
		pb(arr, ints[S_START]);
		ints[S_START]++;
	}
	ints[S_WEIGHT] = ints[S_START];
	// printf("\n A:\n");
	// print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	// printf("\n B:\n");
	// print_a(arr[ARR_B], 0, ints[S_START]);
	ints[S_START]--;
	while (++ints[S_START] < ints[S_SIZE] - 3)
		pb(arr, ints[S_START]);
	do_3(arr[ARR_A], ints[S_START]);
	do_rest(arr, ints);
	finalize_a(arr[ARR_A], ints[S_SIZE]);
}

void	push_swap(int *a, int size)
{
	int	*b;
	int	*c;
	int	*d;
	int	ints[3];
	int	**arr;
	int	i;

	ints[S_START] = 0;
	ints[S_SIZE] = size;
	b = malloc(size * sizeof(int));
	c = malloc(size * sizeof(int));
	d = malloc(size * sizeof(int));
	arr = malloc(4 * sizeof(void(*)));
	arr[ARR_A] = a;
	arr[ARR_B] = b;
	arr[ARR_A2] = c;
	arr[ARR_B2] = d;
	i = -1;
	while (++i < size)
		arr[ARR_A2][i] = arr[ARR_A][i];
	if (ints[S_SIZE] == 2)
		do_2(arr[ARR_A], ints[S_START]);
	else if (ints[S_SIZE] == 3)
		do_3(arr[ARR_A], ints[S_START]);
	else
		do_more(arr, ints);
	// printf("\n");
	// print_a(arr[ARR_A], 0, ints[S_SIZE]);
}

int	*pre_order(int *a, int size)
{
	int	i;
	int	j;
	int	val;
	int	*c;

	c = malloc(size * sizeof(int));
	if (!c)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		j = -1;
		val = 0;
		while (++j < size)
			if (a[j] > a[i])
				val++;
		c[i] = size - 1 - val;
	}
	free(a);
	return (c);
}
