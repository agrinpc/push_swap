/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:26:51 by miahmadi          #+#    #+#             */
/*   Updated: 2022/09/03 12:20:41 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	return (0);
}

int	main(int argc, char **argv)
{
	int	input;
	int	size;
	int	*a;

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
		check_push_swap(a, size);
	}
	return (0);
}
