/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:38:28 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/03/30 18:38:31 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

char	**get_val_arr(int argc, char **argv);
int		arr_size(char **argv);
int		validate_numbs(int start, int size, char **vals);
int		over_checker(const char *str);
int		find_smallest_pos(t_stack *lst);
int		check_ordered(t_stack *lst, t_stack *end);
int		check_reverse_ordered(t_stack *lst, t_stack *end);
int		smallest_val(t_stack *lst);
int		biggest_val(t_stack *lst);
int		ft_lstsize_test(t_stack *start, t_stack *stop);
int		smallest_val_test(t_stack *start, t_stack *stop);
int		biggest_val_test(t_stack *start, t_stack *stop);
int		get_pivot_test(t_stack *start, t_stack *end);
int		get_pivot_test_test(t_stack *start, t_stack *end, int size);
int		is_bigger(t_stack *st, int val);
int		is_smaller(t_stack *st, int val);
int		biggest_pos(t_stack *st);
int		smallest_pos(t_stack *st, int size);
int		find_fit(t_stack *st, int pos, int size);
int		calc_a_rots(t_stack *st, int pos, int size);
int		calc_b_rots(t_stack *st, int pos, int size);
int		shaking_rot(int rots_a, int rots_b, int size_a, int size_b);
int		crying_rot(int rots_a, int rots_b, int size_a, int size_b);
int		worst_case_rot(int rots_a, int rots_b, int size_a, int size_b);
int		calc_rot(t_stack **a, t_stack **b, int pos, int *arr);
int		shaking_and_crying(int rots_a, int rots_b, int *arr);
int		crying_and_shaking(int rots_a, int rots_b, int *arr);
t_stack	*find_stop_pos(t_stack *lst, int stop);
t_stack	*create_stack(int start, int size, char **vals);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	sa(t_stack **a, int from_r);
void	sb(t_stack **b, int from_r);
void	ss(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int from_r);
void	rb(t_stack **b, int from_r);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int from_r);
void	rrb(t_stack **b, int from_r);
void	rrr(t_stack **a, t_stack **b, int print);
void	free_arr(char **arr, int start, int size);
void	start_sort(int argc, int start, int size, char **arr);
void	list_stacks(t_stack *a, t_stack *b);
void	sort_two(t_stack **a);
void	sort_triple(t_stack **a);
void	sort_quad(t_stack **a, t_stack **b);
void	sort_penta(t_stack **a, t_stack **b);
void	set_pos(t_stack **stack);
void	print_list_with_order(t_stack *st);
void	calc_handler(t_stack **a, t_stack **b, int val, int *arr);
void	insert_sort(t_stack **a, t_stack **b);

#endif