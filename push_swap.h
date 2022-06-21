/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:38:44 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/21 01:01:02 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

# define RAT 1
# define S_START 0
# define S_SIZE 1
# define S_WEIGHT 2
# define ARR_A 0
# define ARR_B 1
# define ARR_C 2

void	push_swap(int *a, int size);
int		*pre_order(int *a, int size);
int		return_b_r(int size, int i);
int		get_rr_rrr(int max, int val, int *b, int start);
int		is_odd(int num);
void	sa(int *a, int start);
void	sb(int *b, int size);
void	pb(int **arr, int start);
void	pa(int **arr, int start);
void	rr(int *a, int *b, int start, int size);
void	rrr(int *a, int *b, int start, int size);
void	rb(int *b, int start, int size);
void	ra(int *a, int start, int size);
void	rrb(int *b, int start, int size);
void	rra(int *a, int start, int size);
int		ft_atoi(const char *nptr);
void	print_a(int *a, int start, int size);

#endif
