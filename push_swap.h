/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:38:44 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/25 14:18:09 by miahmadi         ###   ########.fr       */
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
# define ARR_A2 2
# define ARR_B2 3

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
void	fsa(int *a, int start);
void	fsb(int *b, int size);
void	fpb(int **arr, int start);
void	fpa(int **arr, int start);
void	frr(int *a, int *b, int start, int size);
void	frrr(int *a, int *b, int start, int size);
void	frb(int *b, int start, int size);
void	fra(int *a, int start, int size);
void	frrb(int *b, int start, int size);
void	frra(int *a, int start, int size);
int		ft_atoi(const char *nptr);
void	print_a(int *a, int start, int size);
int		get_elm_index(int ints[3], int max);
void	pull_a_to_top(int **arr, int ints[3], int i, int b_rot);
void	pull_a2_to_top(int **arr, int ints[3], int i, int b_rot);

#endif
