/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:36:26 by miahmadi          #+#    #+#             */
/*   Updated: 2022/08/29 23:48:00 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**free_b(int *a)
{
	free(a);
	return (NULL);
}

int	**free_c(int *a, int *b)
{
	free(a);
	free(b);
	return (NULL);
}

int	**free_d(int *a, int *b, int *c)
{
	free(a);
	free(b);
	free(c);
	return (NULL);
}

int	**free_all(int *a, int *b, int *c, int *d)
{
	free(a);
	free(b);
	free(c);
	free(d);
	return (NULL);
}
