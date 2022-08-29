/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:17:23 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 23:18:19 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fsa(int *a, int start)
{
	int	tmp;

	tmp = a[start];
	a[start] = a[start + 1];
	a[start + 1] = tmp;
}

void	fsb(int *b, int size)
{
	int	tmp;

	tmp = b[size - 1];
	b[size - 1] = b[size - 2];
	b[size - 2] = tmp;
}

void	fpb(int **arr, int start)
{
	arr[ARR_B2][start] = arr[ARR_A2][start];
}

void	fpa(int **arr, int start)
{
	arr[ARR_A2][start] = arr[ARR_B2][start];
}

void	frra(int *a, int start, int size)
{
	int	i;
	int	tmp;

	i = size;
	tmp = a[size - 1];
	while (--i > start)
		a[i] = a[i - 1];
	a[start] = tmp;
}
