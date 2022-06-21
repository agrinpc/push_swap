/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 06:21:18 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/21 06:37:58 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int		i;
	int		*a;
	char	*str;

	i = 0;
	a = malloc((argc - 1) * sizeof(int));
	while (++i < argc)
	{;
		str = argv[i];
		a[i - 1] = ft_atoi(str);
	}
	print_a(a, 0, argc - 1);
	a = pre_order(a, argc - 1);
	push_swap(a, argc - 1);
	return (0);
}