/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:47:39 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/30 00:50:00 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_check(int **arr, int ints[3])
{
	int	i;

	i = -1;
	while (++i < ints[S_SIZE] - 1)
	{
		if (arr[ARR_A][i + 1] < arr[ARR_A][i])
		{
			ft_printf("KO\n");
			return ;
		}
	}
	ft_printf("OK\n");
}

int	do_check(char *str, int **arr, int ints[3])
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(arr[ARR_A], ints[S_START]);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(arr[ARR_B], ints[S_START]);
	else if (!ft_strncmp(str, "pa\n", 3) && --ints[S_START] > -1)
		pa(arr, ints[S_START]);
	else if (!ft_strncmp(str, "pb\n", 3) && ++ints[S_START])
		pb(arr, ints[S_START] - 1);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(arr[ARR_B], 0, ints[S_START]);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(arr[ARR_B], 0, ints[S_START]);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(arr[ARR_A], arr[ARR_B], ints[S_START], ints[S_SIZE]);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(arr[ARR_A], arr[ARR_B], ints[S_START], ints[S_SIZE]);
	else
		return (0);
	return (1);
}

void	check_push_swap(int *a, int size)
{
	int		ints[3];
	int		**arr;
	char	*str;
	int		check;

	ints[S_START] = 0;
	ints[S_SIZE] = size;
	arr = make_arrays_bonus(a, size);
	str = get_next_line(0);
	while (str)
	{
		check = do_check(str, arr, ints);
		if (!check)
		{
			ft_printf("KO\n");
			return ;
		}
		str = get_next_line(0);
	}
	final_check(arr, ints);
	free_arrays_bonus(arr);
}
