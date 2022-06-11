/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:06:21 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/09 14:33:12 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define ROWS 2

void	sa(int *a, int start)
{
	int	tmp;

	tmp = a[start];
	a[start] = a[start + 1];
	a[start + 1] = tmp;
	// printf("sa\n");
}

void	sb(int *b, int size)
{
	int	tmp;

	tmp = b[size - 1];
	b[size - 1] = b[size - 2];
	b[size - 2] = tmp;
	// printf("sb\n");
}

void	pa(int *a, int *b, int start)
{
	b[start] = a[start];
	// printf("pa\n");
}

void	pb(int *b, int *a, int start)
{
	a[start - 1] = b[start];
	// printf("pb\n");
}

void	rra(int *a, int start, int size)
{
	int	i;
	int	tmp;

	i = size;
	tmp = a[size - 1];
	while (--i > start)
		a[i] = a[i - 1];
	a[start] = tmp;
	// printf("rra\n");
}

void	rb(int *b, int start, int size)
{
	int	i;
	int	tmp;

	i = size;
	tmp = b[size - 1];
	while (--i > start)
		b[i] = b[i - 1];
	b[start] = tmp;
	// printf("rb\n");
}

void	ra(int *a, int start, int size)
{
	int	i;
	int tmp;
	
	i = start - 1;
	tmp = a[start];
	while (++i < size - 1)
		a[i] = a[i + 1];
	a[size - 1] = tmp;
	// printf("ra\n");
}

void	rrb(int *b, int start, int size)
{
	int	i;
	int tmp;
	
	i = start - 1;
	tmp = b[start];
	while (++i < size - 1)
		b[i] = b[i + 1];
	b[size - 1] = tmp;
	// printf("rrb\n");
}

void	print_a(int *a, int start, int size)
{
	int	i;

	i = start - 1;
	printf("\n\n *********************************** \n");
	while (++i < size)
		printf("%d\n", a[i]);
}

int	get_b_index(int *b, int val, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (val < b[i + 1] && val > b[i])
			return (i);
	}
	
	return (i);
}

void sort_b(int *b, int size, int i)
{
	int j;

	if (i > 0)
	{
		if (i > size / 2)
		{
			j = i;
			while (++j < size)
				rrb(b, 0, size);
			sb(b, size);
			j = i;
			while (++j < size)
				rb(b, 0, size);
		}
		else
		{
			j = 0;
			while (++j < i)
				rb(b, 0, size);
			sb(b, size);
			j = i;
			while (++j < i)
				rrb(b, 0, size);
		}
	}
}

int	get_small_elm(int *a, int size, int start)
{
	int	sm;
	int	*tmp;
	int	i;
	int	max;

	i = 0;
	max = 0;
	tmp = malloc(2 * sizeof(int) * ROWS);
	while (i < ROWS)
	{
		tmp[i * 2] = a[start + i];
		tmp[i * 2 + 1] = a[size - i - 1];
		i++;
	}
	i = 0;
	while (++i < 2 * ROWS)
		if (tmp[i] < tmp[max])
			max = i;
	// print_a(tmp, 2 * ROWS);
	return (max);
}

int	is_odd(int num)
{
	if (num % 2 == 0)
		return (1);
	return (0);
}

int do_it(int *a, int *b, int start, int size)
{
	int	max;
	int	i;
	int j;

	i = -1;
	max = get_small_elm(a, size, start);
	printf("\nmax = %d\n", max);
	// printf("max is %d\n", max);
	if (is_odd(max))
		while (++i < max / 2)
			ra(a, start, size);
	else
		while (++i < max / 2 + 1)
			rra(a, start, size);
	printf("\na0 = %d\n", a[start]);
	j = get_b_index(b, a[start], start);
	printf("\n j = %d\n", j);
	sort_b(b, start, j);
	pa(a, b, start);
	// cond(b, a, 0, start);
	// printf("\n b ");
}

void do_2(int *a, int start)
{
	if (a[start] > a[start + 1])
		sa(a, start);
}

void do_3(int *a, int start)
{
	if (a[start] > a[start + 1])
		sa(a, start);
	if (a[start] > a[start + 2])
		ra(a, start, start + 3);
	if (a[1] > a[2])
	{
		ra(a, start, start + 3);
		sa(a, start);
		rra(a, start, start + 3);
	}
}

int cond(int *a, int *b, int start, int size)
{
	int	i;

	i = -1;
	if (size < 2)
		return (start);
	if (size < 3)
		do_2(a, start);
	else if (size < 4)
		do_3(a, start);
	else if (start < size - 1)
	{
		do_it(a, b, start, size);
		start++;
		print_a(b, 0, start);
		start = cond(a, b, start, size);
	} else {
		while (++i < start)
			pa(b, a, i);
		start = 0;
	}
	return (start);
}

void	push_swap(int *a, int size)
{
	int	*b;
	int	max;
	int	start;
	int	i;

	start = 0;
	i = -1;
	print_a(a, start, size);
	b = malloc(size * sizeof(int));
	start = cond(a, b, start, size);
	print_a(b, 0, size);
	print_a(a, start, size);
}

int main()
{
	int	size = 4;
	int	a[4] = {-122, -20, 125, -50};
	// , 0, 18, -1000, 10, 126, -19, 999, -1236, -156, 732, 199};

	push_swap(a, size);
	return (0);
}
