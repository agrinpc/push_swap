/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:39:04 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 23:09:08 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cpy_arr(int *src, int *dst, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		dst[i] = src[i];
	}
}

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

int	abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int	is_odd(int num)
{
	if (num % 2 == 0)
		return (1);
	return (0);
}

int	get_elm_index(int ints[3], int max)
{
	if (is_odd(max))
		return (max / 2);
	return (ints[S_SIZE] - ints[S_START] - 1 - (max / 2));
}
