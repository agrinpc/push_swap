/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:41:30 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/14 18:19:26 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if ((c > 47 && c < 58))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	output;

	sign = 1;
	output = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr)
	{
		if (ft_isdigit(*nptr))
			output = output * 10 + (*nptr - 48);
		else
			return (sign * output);
		nptr++;
	}
	return (sign * output);
}

void	print_a(int *a, int start, int size)
{
	int	i;

	i = start - 1;
	while (++i < size)
		printf("%d\n", a[i]);
	printf("*********************\n");
}
