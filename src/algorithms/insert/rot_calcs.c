/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_calcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:28:59 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/07/10 16:29:00 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

int	calc_a_rots(t_stack *st, int pos, int size)
{
	t_stack	*temp;
	int		n;

	temp = st;
	n = 0;
	while (temp != NULL && temp->pos != pos)
	{
		n++;
		temp = temp->next;
	}
	if (n > size / 2)
		n -= size;
	return (n);
}

int	calc_b_rots(t_stack *st, int pos, int size)
{
	int	n;

	if (st == NULL)
		return (0);
	if (is_bigger(st, pos))
		n = biggest_pos(st);
	else if (is_smaller(st, pos))
		n = smallest_pos(st, size);
	else
		n = find_fit(st, pos, size);
	return (n);
}

int	shaking_rot(int rots_a, int rots_b, int size_a, int size_b)
{
	int	diff;
	int	num;
	int	invert_a;
	int	invert_b;

	num = rots_a - rots_b;
	invert_a = (rots_a - size_a);
	invert_b = (size_b + rots_b);
	if (invert_a < rots_b)
		diff = invert_a;
	else
		diff = rots_b;
	if ((diff * (-1)) < num)
		num = diff * (-1);
	if (invert_b > rots_a)
		diff = invert_b;
	else
		diff = rots_a;
	if (diff < num)
		num = diff;
	return (num);
}

int	crying_rot(int rots_a, int rots_b, int size_a, int size_b)
{
	int	diff;
	int	num;
	int	invert_a;
	int	invert_b;

	num = (rots_b - rots_a);
	invert_a = (size_a + rots_a);
	invert_b = (rots_b - size_b);
	if (invert_a > rots_b)
		diff = invert_a;
	else
		diff = rots_b;
	if (diff < num)
		num = diff;
	if (invert_b < rots_a)
		diff = invert_b;
	else
		diff = rots_a;
	if ((diff * (-1)) < num)
		num = diff * (-1);
	return (num);
}

int	calc_rot(t_stack **a, t_stack **b, int pos, int *arr)
{
	int	num;
	int	rots_a;
	int	rots_b;

	rots_a = calc_a_rots(*a, pos, arr[3]);
	rots_b = calc_b_rots(*b, pos, arr[4]);
	num = rots_a;
	if (b != NULL && rots_a == 0)
		num = rots_b;
	if (b != NULL && rots_a != 0 && rots_b != 0)
	{
		if (rots_a > 0 && rots_b > 0 && rots_a < rots_b)
			num = rots_b;
		else if (rots_a < 0 && rots_b < 0 && rots_a > rots_b)
			num = rots_b;
		else if (rots_a > 0 && rots_b < 0)
			num = shaking_rot(rots_a, rots_b, arr[3], arr[4]);
		else if (rots_a < 0 && rots_b > 0)
			num = crying_rot(rots_a, rots_b, arr[3], arr[4]);
	}
	if (num < 0)
		num *= -1;
	return (num);
}
