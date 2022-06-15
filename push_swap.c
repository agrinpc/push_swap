/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:06:21 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/14 18:16:23 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rows(int size)
{
	if (size < 13)
		return (3);
	if (size < 100)
		return (6);
	if (size < 300)
		return (10);
	if (size < 501)
		return (15);
	return (20);
}

void	print_a(int *a, int start, int size)
{
	int	i;

	i = start - 1;
	while (++i < size)
		printf("%d\n", a[i]);
	printf("*********************\n");
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
	int	sm;
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

int	get_small_elm_1(int *a, int *b, int size, int start)
{
	int	sm;
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
		if (tmp[i] < tmp[max])
			max = i;
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
	tmp = return_b_r(b, start, j);
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

int return_b_r(int *b, int size, int i)
{
	if (size < 2)
		return (0);
	if (size - i < size / 2)
		return (size - 2);
	return (-i - 1);
}

int	is_odd(int num)
{
	if (num % 2 == 0)
		return (1);
	return (0);
}

void do_it_1(int *a, int *b, int start, int size)
{
	int	max;
	int	i;
	int j;
	int	tmp;

	i = -1;
	max = get_small_elm_1(a, b, size, start);
	if (is_odd(max))
	{
		j = get_b_index(b, a[max / 2], start);
		tmp = return_b_r(b, start, j);
		while (++i < max / 2)
		{
			if (tmp > 0)
			{
				if (i < tmp)
					rr(a, b, start, size);
			}
			else
				ra(a, start, size);
		}
	}
	else
	{
		j = get_b_index(b, a[size - (max + 1) / 2], start);
		tmp = return_b_r(b, start, j);
		while (++i < max / 2 + 1)
		{
			if (tmp < 0)
			{
				if (i < -tmp)
					rrr(a, b, start, size);
			}
			else
				rra(a, start, size);
		}
	}
	j = get_b_index(b, a[start], start);
	sort_b(b, start, j);
	pb(a, b, start);
}

void do_it_2(int *a, int *b, int start, int size)
{
	int	max;
	int	i;
	int	j;
	int	tmp;

	i = -1;
	max = get_small_elm_2(a, b, size, start);
	if (is_odd(max))
	{
		j = get_b_index(b, a[max / 2], start);
		tmp = return_b_r(b, start, j);
		while (++i < max / 2)
		{
			if (tmp > 0)
			{
				if (i < tmp)
					rr(a, b, start, size);
			}
			else
				ra(a, start, size);
		}
	}
	else
	{
		j = get_b_index(b, a[size - (max + 1) / 2], start);
		tmp = return_b_r(b, start, j);
		while (++i < max / 2 + 1)
		{
			if (tmp < 0)
			{
				if (i < -tmp)
					rrr(a, b, start, size);
			}
			else
				rra(a, start, size);
		}
	}
	j = get_b_index(b, a[start], start);
	sort_b(b, start, j);
	pb(a, b, start);
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

int	cond(int *a, int *b, int start, int size)
{
	int	i;

	i = -1;
	if (size < 2)
		return (start);
	if (size < 3)
		do_2(a, start);
	else if (size < 4)
		do_3(a, start);
	else if (start < size * RAT)
	{
		do_it_2(a, b, start, size);
		start++;
		start = cond(a, b, start, size);
	}
	else if (start < size)
	{
		do_it_1(a, b, start, size);
		start++;
		start = cond(a, b, start, size);
	} else {
		finalize_b(b, start);
		while (++i < start)
			pa(b, a, i);
		start = 0;
	}
	return (start);
}

void	push_swap(int *a, int size)
{
	int	*b;
	int	*c;
	int	max;
	int	start;
	int	i;

	start = 0;
	i = -1;
	b = malloc(size * sizeof(int));
	c = malloc(size * sizeof(int));
	start = cond(a, b, start, size);
}

int main(int argc, char *argv[])
{
	int		i;
	int		*a;
	char	*str;

	i = 0;
	a = malloc((argc - 1) * sizeof(int));
	while (++i < argc)
	{
		str = argv[i];
		a[i - 1] = ft_atoi(str);
	}
	push_swap(a, argc - 1);
	return (0);
}
