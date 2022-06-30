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

int	get_rows(int size)
{
	if (size < 5)
		return (1);
	if (size < 13)
		return (2);
	if (size < 101)
		return (6);
	if (size < 301)
		return (11);
	if (size < 501)
		return (16);
	return (20);
}

void	cpy_arr(int *src, int *dst, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		dst[i] = src[i];
	}
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

int	get_a_index(int *a, int val, int start, int size)
{
	int	i;

	i = start - 1;
	while (++i < size - 1)
	{
		if (val > a[i])
			if (val < a[i + 1] || a[i + 1] < a[i])
				return (i);
		if (val < a[i + 1] && a[i + 1] < a[i])
			return (i);
	}
	return (size - 1);
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

void sort_a(int *a, int ints[3], int a_rot)
{
	int	j;

	if (ints[S_SIZE] - ints[S_START] < 2)
		return ;
	j = -1;
	if (a_rot > 0)
		while (++j < a_rot)
			rra(a, ints[S_START], ints[S_SIZE]);
	else
		while (++j < -a_rot)
			ra(a, ints[S_START], ints[S_SIZE]);
}

void sort_b2(int *b, int size, int i)
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

int	abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int	get_moves_count_b(int **arr, int ints[3], int val, int i)
{
	return (get_b_index_cmp(arr[ARR_B], val, ints[S_START]) + (i / 2 + i % 2) - get_rr_rrr(i, val, arr[ARR_B], ints[S_START]));
}

int	get_moves_count_b2(int **arr, int ints[3], int val, int i)
{
	return (get_b_index_cmp(arr[ARR_B2], val, ints[S_START]) + (i / 2 + i % 2) - get_rr_rrr(i, val, arr[ARR_B2], ints[S_START]));
}

int	get_moves_count_a(int **arr, int ints[3], int val, int i)
{
	int	a_indx;
	int a_rot;
	int	b_rot;
	int	ret;

	a_indx = get_a_index(arr[ARR_A], val, ints[S_SIZE], ints[S_SIZE]);
	a_rot = return_a_r(ints, a_indx);
	if (a_rot < 0)
		ret = i - ints[S_START] - a_rot;
	else
	{
		b_rot = i - ints[S_START] - a_rot;
		if (b_rot < 0)
			b_rot = 0;
		ret = b_rot + a_rot;
	}
	return (ret);
}

int get_moves_total(int **arr, int ints[3], int *tmp, int i)
{
	int	rows;
	int	min;
	int	moves;
	int	*tmp2;
	int	j;
	int	elm;
	int	b_indx;
	int	b_rot;
	
	cpy_arr(arr[ARR_A], arr[ARR_A2], ints[S_SIZE]);
	cpy_arr(arr[ARR_B], arr[ARR_B2], ints[S_START]);
	moves = get_moves_count_b2(arr, ints, tmp[i], i);
	elm = get_elm_index(ints, i);
	b_indx = get_b_index(arr[ARR_B2], arr[ARR_A2][elm], ints[S_START]);
	b_rot = return_b_r(ints[S_START], b_indx);
	pull_a2_to_top(arr, ints, elm, b_rot);
	b_indx = get_b_index(arr[ARR_B2], arr[ARR_A2][ints[S_START]], ints[S_START]);
	sort_b2(arr[ARR_B2], ints[S_START], b_indx);
	fpb(arr, ints[S_START]);
	ints[S_START]++;
	rows = get_rows(ints[S_SIZE] - ints[S_START]);
	tmp2 = malloc(2 * sizeof(int) * rows);
	j = -1;
	while (++j < rows)
	{
		tmp2[j * 2] = arr[ARR_A2][ints[S_START] + j];
		tmp2[j * 2 + 1] = arr[ARR_A2][ints[S_SIZE] - j - 1];
	}
	j = 0;
	min = 0;
	while (++j < 2 * rows)
		if (get_moves_count_b2(arr, ints, tmp2[j], j) < get_moves_count_b2(arr, ints, tmp[min], min))
			min = j;
	ints[S_START]--;
	return (moves + get_moves_count_b2(arr, ints, tmp[min], min));
}

int	get_elm_index(int ints[3], int max)
{
	if (is_odd(max))
		return (max / 2);
	return (ints[S_SIZE] - ints[S_START] - 1 - (max / 2));
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

int	get_elm_in_a(int **arr, int ints[3])
{
	int	*tmp;
	int	i;
	int	max;
	int	rows;

	i = -1;
	max = 0;
	if (ints[S_SIZE] - ints[S_START] > 2)
		rows = 2 * get_rows(ints[S_WEIGHT]);
	else
		return (0);
	if (rows > ints[S_START] - ints[S_WEIGHT])
		rows = ints[S_START] - ints[S_WEIGHT];
	tmp = malloc(rows);
	while (++i < rows)
		tmp[i] = arr[ARR_B][ints[S_START] - i];
	i = 0;
	while (++i < rows)
		if (get_moves_count_a(arr, ints, tmp[i], i) < get_moves_count_a(arr, ints, tmp[max], max))
			max = i;
	free(tmp);
	// printf("\n*** max = %d ***\n", max);
	return (max);
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

int return_a_r(int ints[3], int a_index)
{
	// printf("\n*** size = %d, start = %d, a_index = %d ***\n", ints[S_SIZE], ints[S_START], a_index);
	if (a_index == ints[S_SIZE] - 1)
		return (0);
	if (abs(a_index - ints[S_START]) > abs(ints[S_SIZE] - 1 - a_index))
		return (ints[S_SIZE] - a_index);
	else
		return (ints[S_START] - a_index - 1);
	return (0);
}

int	is_odd(int num)
{
	if (num % 2 == 0)
		return (1);
	return (0);
}

void	finalize_a(int *a, int size)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (++i < size)
		if (a[i] > a[max])
			max = i;
	i = -1;
	// printf("\n ** max = %d\n", max);
	if (max < size / 2)
		while (++i <= max)
			ra(a, 0, size);
	else
		while (++max < size)
			rra(a, 0, size);
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

void	pull_b_to_top(int **arr, int ints[3], int i, int a_rot)
{
	int	j;

	j = -1;
	// printf("\n*** start = %d, i = %d, a_rot = %d ***\n", ints[S_START], i, a_rot);
	while (++j < i - ints[S_START])
	{
		if (a_rot > 0 && j < a_rot)
			rr(arr[ARR_A], arr[ARR_B], ints[S_START], ints[S_SIZE]);
		else
			rb(arr[ARR_B], ints[S_START], ints[S_SIZE]);
	}
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

void	do_rest(int	**arr, int ints[3])
{
	int	i;
	int	a_indx;
	int	a_rot;
	int	elm;

	i = ints[S_START];
	while (--i > ints[S_WEIGHT])
	{
		// print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
		elm = get_elm_in_a(arr, ints) + ints[S_START] - 1;
		a_indx = get_a_index(arr[ARR_A], arr[ARR_A][elm], ints[S_START], ints[S_SIZE]);
		a_rot = return_a_r(ints, a_indx);
			// printf("\n*** size = %d, start = %d, a_rot = %d, elm = %d, a_index = %d ****\n", ints[S_SIZE], ints[S_START], a_rot, arr[ARR_B][elm], a_indx);
		pull_b_to_top(arr, ints, elm, a_rot);
		a_indx = get_a_index(arr[ARR_A], arr[ARR_A][elm], ints[S_START], ints[S_SIZE]);
		a_rot = return_a_r(ints, a_indx);
		sort_a(arr[ARR_A], ints, a_rot);
		// print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
		pa(arr, ints[S_SIZE]);
		ints[S_START]--;
		print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	}
	i++;
	while (--i > -1)
	{
		a_indx = get_a_index(arr[ARR_A], arr[ARR_B][i], ints[S_START], ints[S_SIZE]);
		a_rot = return_a_r(ints, a_indx);
		if (arr[ARR_B][i] == 8)
			printf("\n*** size = %d, start = %d, a_rot = %d, elm = %d, a_index = %d ****\n", ints[S_SIZE], ints[S_START], a_rot, arr[ARR_B][i], a_indx);
		sort_a(arr[ARR_A], ints, a_rot);
		pa(arr, ints[S_SIZE]);
		ints[S_START]--;
		print_a(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	}
}

void	do_more(int **arr, int ints[3])
{
	int	elm;
	int b_indx;
	int	b_rot;

	while (ints[S_START] < ints[S_SIZE] * 0.8 - 2)
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
	ints[S_START]--;
	while (++ints[S_START] < ints[S_SIZE] - 2)
		pb(arr, ints[S_START]);
	// do_3(arr[ARR_A], ints[S_START]);
	do_2(arr[ARR_A], ints[S_START]);
	do_rest(arr, ints);
	finalize_a(arr[ARR_A], ints[S_SIZE]);
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
	ints[S_WEIGHT] = return_weight(a, ints);
	if (ints[S_SIZE] == 2)
		do_2(arr[ARR_A], ints[S_START]);
	else if (ints[S_SIZE] == 3)
		do_3(arr[ARR_A], ints[S_START]);
	else
	{
		do_more(arr, ints);
	}
	print_a(arr[ARR_A], 0, ints[S_SIZE]);
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
