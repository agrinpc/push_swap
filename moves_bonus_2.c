/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:19:57 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 23:20:22 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	ra(int *a, int start, int size)
{
	int	i;
	int	tmp;

	i = start - 1;
	tmp = a[start];
	while (++i < size - 1)
		a[i] = a[i + 1];
	a[size - 1] = tmp;
}

void	rrb(int *b, int start, int size)
{
	int	i;
	int	tmp;

	i = start - 1;
	tmp = b[start];
	while (++i < size - 1)
		b[i] = b[i + 1];
	b[size - 1] = tmp;
}
