/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:38:24 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 23:20:20 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int start)
{
	int	tmp;

	tmp = a[start];
	a[start] = a[start + 1];
	a[start + 1] = tmp;
}

void	sb(int *b, int size)
{
	int	tmp;

	tmp = b[size - 1];
	b[size - 1] = b[size - 2];
	b[size - 2] = tmp;
}

void	pb(int **arr, int start)
{
	arr[ARR_B][start] = arr[ARR_A][start];
}

void	pa(int **arr, int start)
{
	arr[ARR_A][start] = arr[ARR_B][start];
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
}
