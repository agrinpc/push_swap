/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:06:21 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/09 12:08:27 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define ROWS 2

void	sa(int *a)
{
	int	tmp;

	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

int	pa(int *a, int *b, int start)
{
	b[start] = a[start];
	return (start++);
}

int	pb(int *b, int *a, int start)
{
	a[start - 1] = b[start];
	return (start--);
}

void	ra(int *a, int start, int size)
{
	int	i;
	int	tmp;

	i = size;
	tmp = a[size - 1];
	while (--i > start)
		a[i] = a[i - 1];
	a[start] = tmp;
}

void	rra(int *a, int start, int size)
{
	int	i;
	int tmp;
	
	i = start - 1;
	tmp = a[start];
	while (++i < size - 1)
		a[i] = a[i + 1];
	a[size - 1] = tmp;
}

void	print_a(int *a, int size)
{
	int	i;

	i = -1;
	printf("\n\n *********************************** \n");
	while (++i < size)
		printf("%d\n", a[i]);
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

	i = -1;
	max = get_small_elm(a, size, start);
	// printf("max is %d\n", max);
	if (is_odd(max))
		while (++i < max / 2)
			rra(a, start, size);
	else
		while (++i < max / 2 + 1)
			rra(a, start, size);
	pa(a, b, start);
	// print_a(a, size);
	// print_a(b, size);
}

void	sort_b(int *b, int size)
{
	if (size < 2)
		return ;
	if (size == 2)
		if (b[1] < b[0])
			sa(b);
	if (size == 3)
	{
		if (b[2] < b[0] || b[2] < b[1])
		{
			ra(b, 0, 3);
			if (b[1] < b[0])
				sa(b);
		}
	}
}

void	push_swap(int *a, int size)
{
	int	*b;
	int	max;
	int	start;
	int	i;

	start = 0;
	i = -1;
	print_a(a, size);
	b = malloc(size * sizeof(int));
	do_it(a, b, start, size);
	start++;
	sort_b(b, start);
	do_it(a, b, start, size);
	start++;
	sort_b(b, start);
	do_it(a, b, start, size);
	start++;
	sort_b(b, start);
	do_it(a, b, start, size);
	start++;
	sort_b(b, start);
	print_a(b, size);
}

int main()
{
	int	a[11] = {12, -20, 25, 188, 132, -225, 12338, -55, -999, 0, 18};
	int	size = 11;

	push_swap(a, size);
	return (0);
}
