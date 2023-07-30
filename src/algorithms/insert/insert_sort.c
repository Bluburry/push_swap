/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:28:43 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/07/10 17:05:36 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	send(t_stack **a, t_stack **b, int val_send, int *arr)
{
	calc_handler(a, b, val_send, arr);
	if (arr[0] > 0)
		while (arr[0]-- > 0)
			ra(a, 0);
	else if (arr[0] < 0)
		while (arr[0]++ < 0)
			rra(a, 0);
	if (arr[1] > 0)
		while (arr[1]-- > 0)
			rb(b, 0);
	else if (arr[1] < 0)
		while (arr[1]++ < 0)
			rrb(b, 0);
	if (arr[2] > 0)
		while (arr[2]-- > 0)
			rr(a, b, 1);
	else if (arr[2] < 0)
		while (arr[2]++ < 0)
			rrr(a, b, 1);
	pb(a, b, 1);
}

void	smart_sort(t_stack **a, t_stack **b, int *arr)
{
	t_stack	*temp_a;
	int		rots;
	int		to_s;
	int		small;

	temp_a = *a;
	small = -1;
	arr[3] = ft_lstsize(*a);
	arr[4] = ft_lstsize(*b);
	while (temp_a != NULL)
	{
		rots = calc_rot(a, b, temp_a->pos, arr);
		if (small < 0 || rots < small)
		{
			small = rots;
			to_s = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	send(a, b, to_s, arr);
}

void	insert_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	*arr;

	arr = (int *) malloc(sizeof(int) * 5);
	set_pos(a);
	size = ft_lstsize(*a);
	while (size--)
		smart_sort(a, b, arr);
	while (*b != NULL)
		pa(a, b, 1);
	if (find_smallest_pos(*a) <= ft_lstsize(*a) / 2)
		while (!check_ordered(*a, NULL))
			ra(a, 0);
	else
		while (!check_ordered(*a, NULL))
			rra(a, 0);
	free(arr);
}
