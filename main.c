/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 06:21:18 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/23 19:50:17 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "moves.c"
// #include "utils.c"
// #include "push_swap.c"

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
	// print_a(a, 0, argc - 1);
	a = pre_order(a, argc - 1);
	// print_a(a, 0, argc - 1);
	push_swap(a, argc - 1);
	return (0);
}

// int main()
// {
// 	int		i;
// 	int		*a;
// 	int		argv[5] = {10,12,8,9,15};
// 	int		argc = 5;

// 	i = -1;
// 	a = malloc((argc - 1) * sizeof(int));
// 	while (++i < argc)
// 	{
// 		a[i] = argv[i];
// 	}
// 	a = pre_order(a, argc - 1);
// 	push_swap(a, argc - 1);
// 	return (0);
// }