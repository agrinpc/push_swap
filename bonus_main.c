/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:26:51 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/30 00:15:25 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	ft_printf("Error\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int	input;
	int	size;
	int	*a;

	input = check_input(argv, argc);
	if (input == 0)
		return (error());
	else if (input == 1)
		size = argc - 1;
	else
		size = has_space(argv[1]);
	a = get_args(argv, size, input);
	if (a)
	{
		if (!validate_numbers(a, size))
			return (error());
		a = pre_order(a, size);
		check_push_swap(a, size);
	}
	else
		ft_printf("Error\n");
	return (0);
}
