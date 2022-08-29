/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 06:21:18 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 23:00:00 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*a;
	int	size;
	int	input;	

	input = check_input(argv, argc);
	if (input == 0)
		return (0);
	else if (input == 1)
		size = argc - 1;
	else
		size = has_space(argv[1]);
	a = get_args(argv, size, input);
	if (a)
	{
		if (!validate_numbers(a, size))
			return (0);
		a = pre_order(a, size);
		push_swap(a, size);
	}
	return (0);
}
