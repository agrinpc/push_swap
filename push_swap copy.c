/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:06:21 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/13 16:07:12 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if ((c > 47 && c < 58))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	output;

	sign = 1;
	output = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr)
	{
		if (ft_isdigit(*nptr))
			output = output * 10 + (*nptr - 48);
		else
			return (sign * output);
		nptr++;
	}
	return (sign * output);
}

int	get_rows(int size)
{
	if (size < 11)
		return (3);
	if (size < 100)
		return (7);
	if (size < 300)
		return (10);
	if (size < 501)
		return (15);
	return (20);
}

void	sa(int *a, int start)
{
	int	tmp;

	tmp = a[start];
	a[start] = a[start + 1];
	a[start + 1] = tmp;
	printf("sa\n");
}

void	sb(int *b, int size)
{
	int	tmp;

	tmp = b[size - 1];
	b[size - 1] = b[size - 2];
	b[size - 2] = tmp;
	printf("sb\n");
}

void	pb(int *a, int *b, int start)
{
	b[start] = a[start];
	printf("pb\n");
}

void	pa(int *b, int *a, int start)
{
	a[start] = b[start];
	printf("pa\n");
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
	printf("rra\n");
}

void	rr(int *a, int *b, int start, int size)
{
	int	i;
	int	tmp;

	i = start - 1;
	tmp = a[start];
	while (++i < size - 1)
		a[i] = a[i + 1];
	a[size - 1] = tmp;
	i = start;
	tmp = b[start - 1];
	while (--i > 0)
		b[i] = b[i - 1];
	b[0] = tmp;
	printf("rr\n");
}

void	rrr(int *a, int *b, int start, int size)
{
	int	i;
	int	tmp;

	i = size;
	tmp = a[size - 1];
	while (--i > start)
		a[i] = a[i - 1];
	a[start] = tmp;
	i = -1;
	tmp = b[0];
	while (++i < start - 1)
		b[i] = b[i + 1];
	b[start - 1] = tmp;
	printf("rrr\n");
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
	printf("rb\n");
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
	printf("ra\n");
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
	printf("rrb\n");
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
	int	ret;

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

int	get_small_elm(int *a, int *b, int size, int start)
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
		if (get_b_index_cmp(b, tmp[i], start) < get_b_index_cmp(b, tmp[max], start))
			max = i;
	return (max);
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

void do_it(int *a, int *b, int start, int size)
{
	int	max;
	int	i;
	int j;
	int	tmp;

	i = -1;
	max = get_small_elm(a, b, size, start);
	// j = get_b_index(b, a[start], start);
	// printf("\nmax = %d\n", max);
	if (is_odd(max))
	{
		// printf("\n##########\n#        #\n#%4.d   #\n#        #\n##########\n", a[max / 2]);
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
		// printf("\n##########\n#        #\n# %d   #\n#        #\n##########\n", a[size - (max + 1) / 2]);
		j = get_b_index(b, a[size - (max + 1) / 2], start);
		tmp = return_b_r(b, start, j);
		// printf("\ntmp = %d\n", tmp);
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
	// printf("\na0 = %d\n", a[start]);
	// printf("\n start = %d\n", start);
	j = get_b_index(b, a[start], start);
	// print_a(a, start, size);
	// printf("\n j = %d\n", j);
	// printf("\nFIRST B, J = %d, start = %d\n", j, start);
	// print_a(b, 0, start);
	sort_b(b, start, j);
	// printf("\nSECOND B\n");
	// print_a(b, 0, start);
	pb(a, b, start);
	start++;
	// printf("\nTHIRD B\n");
	// print_a(b, 0, start);
	// cond(b, a, 0, start);
	// printf("\n b ");
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
	else if (start < size / 7)
	{
		do_it(a, b, start, size);
		start++;
		// print_a(b, 0, start);
		start = cond(a, b, start, size);
	} else {
		finalize_b(b, start);
		// printf("\nstart = %d, a[%d] = %d, a[%d] = %d, a[%d] = %d\n", start, start, a[start], start + 1, a[start + 1], start + 2, a[start + 2]);
		do_3(a, start);
		// while (++i < start)
		// 	pa(b, a, i);
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
	// print_a(a, start, size);
	b = malloc(size * sizeof(int));
	start = cond(a, b, start, size);
	// print_a(b, 0, size);
	// print_a(a, start, size);
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
