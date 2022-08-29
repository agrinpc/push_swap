/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 06:21:18 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 14:33:58 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_space(char *str)
{
	int i;
	int	size;

	i = -1;
	size = 1;
	while (str[++i])
		if (str[i] == ' ')
			size++;
	return (size);
}

int	check_input(char **argv, int argc)
{
	int i;
	int spc;

	i = 0;
	spc = 0;
	while (++i < argc)
	{
		if (has_space(argv[i]) > 1)
		{
			if (argc > 2)
				return (0);
			spc++;
		}
	}
	if (spc == 0)
		return (1);
	return (2);
}

char	**get_numbers(char *str)
{
	int i;
	char **numbers;

	i = -1;
	while (str[++i])
		if (str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
			return (NULL);
	numbers = ft_split(str, ' ');
	return (numbers);
}

int	*get_args(char **argv, int size, int input)
{
	int		*res;
	int		i;
	char	**numbers;

	if (input == 2)
	{
		numbers = get_numbers(argv[1]);
		if (!numbers)
			return (NULL);
		res = malloc((size) * sizeof(int));
		i = -1;
		while (++i < size)
			res[i] = ft_atoi(numbers[i]);
	}
	else
	{
		res = malloc((size) * sizeof(int));
		i = -1;
		while (++i < size)
			res[i] = ft_atoi(argv[i + 1]);
	}
	return (res);
}

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
		a = pre_order(a, size);
		push_swap(a, size);
	}
	return (0);
}
