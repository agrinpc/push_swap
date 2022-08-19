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

# define CHUNKS 5

void	push_swap(int *a, int size);
int		*pre_order(int *a, int size);
int		return_b_r(int size, int i);
int 	return_a_r(int ints[3], int a_index);
int		get_rr_rrr(int max, int val, int *b, int start);
int		get_a_rr_rrr(int max, int val, int *a, int ints[3]);
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
void	sort_a(int *a, int ints[3], int a_rot);
void	sort_b(int *b, int size, int i);
void	sort_b2(int *b, int size, int i);
int		get_moves_count_a(int **arr, int ints[3], int val, int i);
int		get_moves_count_b(int **arr, int ints[3], int val, int i);
int		get_moves_count_b2(int **arr, int ints[3], int val, int i);
void	pull_b_to_top(int **arr, int ints[3], int i, int a_rot);
void	pull_a_to_top(int **arr, int ints[3], int i, int b_rot);
void	pull_a2_to_top(int **arr, int ints[3], int i, int b_rot);
int		get_a_index(int *a, int val, int start, int size);
int		get_b_index(int *b, int val, int size);
int		get_b_index_cmp(int *b, int val, int size);
int		get_elm(int **arr, int ints[3]);
int		get_elm_in_a(int **arr, int ints[3]);
void	finalize_a(int *a, int size);
void	finalize_b(int *b, int start);
void	cpy_arr(int *src, int *dst, int size);
int		get_rows(int size);
int		get_moves_total(int **arr, int ints[3], int *tmp, int i);
int		get_elm_index(int ints[3], int max);
int		get_a_position(int *a, int ints[3], int val);
int		get_elm_in_b(int **arr, int	ints[3], int ch_s, int ch_e);
int		get_b_moves(int **arr, int ints[3], int val);
void	pull_a_to_top_simple(int **arr, int ints[3], int i);

#endif
