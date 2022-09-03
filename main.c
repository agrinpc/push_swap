/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 06:21:18 by miahmadi          #+#    #+#             */
/*   Updated: 2022/09/03 12:21:41 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pre_check(int *a, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (a[i + 1] < a[i])
			return (0);
	}
	return (1);
}

int	error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	return (0);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	size;
	int	input;	

	input = check_input(argv, argc);
	if (input == 0)
		return (error("Arguments combanition is wrong"));
	else if (input == 1)
		size = argc - 1;
	else
		size = count_args(argv[1]);
	if (size < 1 || ft_strncmp(argv[1], "", 1) == 0)
		return (0);
	a = get_args(argv, size, input);
	if (a)
	{
		if (!validate_numbers(a, size))
			return (error("There is a duplicated value"));
		a = pre_order(a, size);
		if (!pre_check(a, size))
			push_swap(a, size);
	}
	return (0);
}
