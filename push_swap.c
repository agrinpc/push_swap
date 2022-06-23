/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:06:21 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/23 21:37:08 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rows(int size)
{
	if (size < 13)
		return (2);
	if (size < 101)
		return (5);
	if (size < 301)
		return (10);
	if (size < 501)
		return (15);
	return (20);
}

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

int	elm_abs(int val1, int val2)
{
	if (val1 - val2 < 0)
		return (val2 - val1);
	return (val1 - val2);
}

int	small_elm_cmp(int val, int *b, int start)
{
	if (elm_abs(val, b[0]) < elm_abs(val, b[start]))
		return (elm_abs(val, b[0]));
	return (elm_abs(val, b[start]));
}

int	get_small_elm_2(int *a, int *b, int size, int start)
{
	int	*tmp;
	int	i;
	int	max;
	int	rows;

	i = 0;
	max = 0;
	rows = get_rows(size - start);
	tmp = malloc(2 * sizeof(int) * rows);
	while (i < rows)
	{
		tmp[i * 2] = a[start + i];
		tmp[i * 2 + 1] = a[size - i - 1];
		i++;
	}
	i = 0;
	while (++i < 2 * rows)
		if (get_b_index_cmp(b, tmp[i], start) + (i / 2 + i % 2) - get_rr_rrr(i, tmp[i], b, start) < get_b_index_cmp(b, tmp[max], start) + (max / 2 + max % 2) - get_rr_rrr(max, tmp[max], b, start) )
			max = i;
	return (max);
}

// int	get_elm(int **arr, int ints[3])
// {
// 	int	*tmp;
// 	int	i;
// 	int	max;
// 	int	rows;

// 	i = 0;
// 	max = 0;
// 	rows = get_rows(ints[S_SIZE] - ints[S_START]);
// 	tmp = malloc(2 * sizeof(int) * rows);
// 	while (i < rows)
// 	{
// 		tmp[i * 2] = arr[ARR_A][ints[S_START] + i];
// 		tmp[i * 2 + 1] = arr[ARR_A][ints[S_SIZE] - i - 1];
// 		i++;
// 	}
// 	i = 0;
// 	while (++i < 2 * rows)
// 		if ((ints[S_WEIGHT] == 1 && tmp[i] > tmp[max]) || (ints[S_WEIGHT] == 0 && tmp[i] < tmp[max]))
// 			max = i;
// 	free(tmp);
// 	if (is_odd(max))
// 		return (max / 2);
// 	return (ints[S_SIZE] - 1 - (max / 2));
// }

int	get_elm(int **arr, int ints[3])
{
	int	*tmp;
	int	i;
	int	max;
	int	rows;

	i = 0;
	max = 0;
	rows = get_rows(ints[S_SIZE] - ints[S_START]);
	tmp = malloc(2 * sizeof(int) * rows);
	while (i < rows)
	{
		tmp[i * 2] = arr[ARR_A][ints[S_START] + i];
		tmp[i * 2 + 1] = arr[ARR_A][ints[S_SIZE] - i - 1];
		i++;
	}
	i = 0;
	while (++i < 2 * rows)
		if (get_b_index_cmp(arr[ARR_B], tmp[i], ints[S_START]) + (i / 2 + i % 2) - get_rr_rrr(i, tmp[i], arr[ARR_B], ints[S_START]) < get_b_index_cmp(arr[ARR_B], tmp[max], ints[S_START]) + (max / 2 + max % 2) - get_rr_rrr(max, tmp[max], arr[ARR_B], ints[S_START]) )
			max = i;
	// printf("\n i = %d, tmp[%d] = %d\n", max, max, tmp[max]);
	free(tmp);
	if (is_odd(max))
		return (max / 2);
	return (ints[S_SIZE] - 1 - (max / 2));
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
		while (++i < max / 2)
			if (tmp > 0 && i < tmp)
				ret++;
	}
	else
		while (++i < max / 2 + 1)
			if (tmp < 0 && i < -tmp)
				ret++;
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

int	is_odd(int num)
{
	if (num % 2 == 0)
		return (1);
	return (0);
}

// void do_it_2(int *a, int *b, int ints[3])
// {
// 	int	max;
// 	int	i;
// 	int	j;
// 	int	tmp;

// 	i = -1;
// 	max = get_small_elm_2(a, b, ints[S_SIZE], ints[S_START]);
// 	if (is_odd(max))
// 	{
// 		j = get_b_index(b, a[max / 2], ints[S_START]);
// 		tmp = return_b_r(ints[S_START], j);
// 		while (++i < max / 2)
// 		{
// 			if (tmp > 0)
// 			{
// 				if (i < tmp)
// 					rr(a, b, ints[S_START], ints[S_SIZE]);
// 			}
// 			else
// 				ra(a, ints[S_START], ints[S_SIZE]);
// 		}
// 	}
// 	else
// 	{
// 		j = get_b_index(b, a[ints[S_SIZE] - (max + 1) / 2], ints[S_START]);
// 		tmp = return_b_r(ints[S_START], j);
// 		while (++i < max / 2 + 1)
// 		{
// 			if (tmp < 0)
// 			{
// 				if (i < -tmp)
// 					rrr(a, b, ints[S_START], ints[S_SIZE]);
// 			}
// 			else
// 				rra(a, ints[S_START], ints[S_SIZE]);
// 		}
// 	}
// 	j = get_b_index(b, a[ints[S_START]], ints[S_START]);
// 	sort_b(b, ints[S_START], j);
// 	pb(arr, ints[S_START]);
// }

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

void	do_more(int **arr, int ints[3])
{
	int	elm;
	int b_indx;
	int	b_rot;
	int	i;

	while (ints[S_START] < ints[S_SIZE])
	{
		elm = get_elm(arr, ints) + ints[S_START];
		b_indx = get_b_index(arr[ARR_B], arr[ARR_A][elm], ints[S_START]);
		b_rot = return_b_r(ints[S_START], b_indx);
		printf("\n elm = %d, b_index = %d, b_rot = %d\n", arr[ARR_A][elm], b_indx, b_rot);
		print_a(arr[ARR_B], 0, ints[S_START]);
		pull_a_to_top(arr, ints, elm, b_rot);
		b_indx = get_b_index(arr[ARR_B], arr[ARR_A][elm], ints[S_START]);
		sort_b(arr[ARR_B], ints[S_START], b_indx);
		pb(arr, ints[S_START]);
		ints[S_START]++;
	}
	// print_a(arr[ARR_B], 0, ints[S_START]);
	finalize_b(arr[ARR_B], ints[S_START]);
	// print_a(arr[ARR_B], 0, ints[S_START]);
	i = -1;
	while (++i < ints[S_SIZE])
		pa(arr, ints[S_START]);
}

int	return_weight(int *a, int ints[3])
{
	int	i;
	int	w;
	int	c;

	w = 0;
	c = 0;
	i = -1;
	while (++i < ints[S_SIZE] / 4 && ++c)
		w += a[i];
	i = ints[S_SIZE];
	while (--i > 3 * ints[S_SIZE] / 4 && ++c)
		w += a[i];
	if (w / c < (ints[S_SIZE] + 1) / 2)
		return (0);
	return (1);
}

void	push_swap(int *a, int size)
{
	int	*b;
	int	*c;
	int	ints[3];
	int	**arr;

	ints[S_START] = 0;
	ints[S_SIZE] = size;
	b = malloc(size * sizeof(int));
	c = malloc(size * sizeof(int));
	arr = malloc(3);
	arr[ARR_A] = a;
	arr[ARR_B] = b;
	arr[ARR_C] = c;
	ints[S_WEIGHT] = return_weight(a, ints);
	if (ints[S_SIZE] == 2)
		do_2(arr[ARR_A], ints[S_START]);
	else if (ints[S_SIZE] == 3)
		do_3(arr[ARR_A], ints[S_START]);
	else
	{
		do_more(arr, ints);
	}
	print_a(arr[ARR_B], 0, ints[S_START]);
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
