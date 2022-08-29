/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:26:51 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 18:00:31 by miahmadi         ###   ########.fr       */
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

int	*pre_order(int *a, int size)
{
	int	i;
	int	j;
	int	val;
	int	*c;

	c = malloc(size * sizeof(int));
	if (!c)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		j = -1;
		val = 0;
		while (++j < size)
			if (a[j] > a[i])
				val++;
		c[i] = size - 1 - val;
	}
	free(a);
	return (c);
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
	else if (!ft_strncmp(str, "pa\n", 3) && ints[S_START]++)
		pa(arr, ints[S_START]);
	else if (!ft_strncmp(str, "pb\n", 3) && ints[S_START]--)
		pb(arr, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(arr[ARR_B], 0, ints[S_SIZE]);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(arr[ARR_A], ints[S_START], ints[S_SIZE]);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(arr[ARR_B], ints[S_START], ints[S_SIZE]);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(arr[ARR_A], arr[ARR_B], ints[S_START], ints[S_SIZE]);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(arr[ARR_A], arr[ARR_B], ints[S_START], ints[S_SIZE]);
	else
		return (0);
	return (1);
}

int	**make_arrays(int *a, int size)
{
	int	*b;
	int	**arr;

	b = malloc(size * sizeof(int));
	if (!b)
		return (NULL);
	arr = malloc(4 * sizeof(char *));
	arr[ARR_A] = a;
	arr[ARR_B] = b;
	return (arr);
}

void free_arrays(int **arr)
{
	free(arr[ARR_A]);
	free(arr[ARR_B]);
}

void	check_push_swap(int *a, int size)
{
	int		ints[3];
	int		**arr;
	char	*str;
	int		check;

	ints[S_START] = 0;
	ints[S_SIZE] = size;
	arr = make_arrays(a, size);
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
	free_arrays(arr);
}

int	main(int argc, char **argv)
{
	int	input;
	int	size;
	int	*a;
	
	input = check_input(argv, argc);
	if (input == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (input == 1)
		size = argc - 1;
	else
		size = has_space(argv[1]);
	a = get_args(argv, size, input);
	if (a)
	{
		a = pre_order(a, size);
		check_push_swap(a, size);
	}
	
	return (0);
}