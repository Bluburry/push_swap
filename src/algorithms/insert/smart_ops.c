/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:29:06 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/07/10 16:29:07 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

int	shaking_crying(int rots_a, int rots_b, int *arr, int choice)
{
	int	diff;
	int	num;
	int	invert_b;

	num = rots_a - rots_b;
	invert_b = (arr[4] + rots_b);
	if (invert_b > rots_a)
		diff = invert_b;
	else
		diff = rots_a;
	if (diff < num)
	{
		num = diff;
		choice = 4;
		if (diff == invert_b)
			choice = 3;
	}
	return (choice);
}

int	shaking_and_crying(int rots_a, int rots_b, int *arr)
{
	int	choice;
	int	diff;
	int	num;
	int	invert_a;

	choice = 0;
	num = rots_a - rots_b;
	invert_a = (rots_a - arr[3]);
	if (invert_a < rots_b)
		diff = invert_a;
	else
		diff = rots_b;
	if ((diff * (-1)) < num)
	{
		num = diff * (-1);
		choice = 2;
		if (diff == invert_a)
			choice = 1;
	}
	return (shaking_crying(rots_a, rots_b, arr, choice));
}

int	crying_shaking(int rots_a, int rots_b, int *arr, int choice)
{
	int	diff;
	int	num;
	int	invert_b;

	num = (rots_b - rots_a);
	invert_b = (rots_b - arr[4]);
	if (invert_b < rots_a)
		diff = invert_b;
	else
		diff = rots_a;
	if ((diff * (-1)) < num)
	{
		num = diff * (-1);
		choice = 4;
		if (diff == invert_b)
			choice = 3;
	}
	return (choice);
}

int	crying_and_shaking(int rots_a, int rots_b, int *arr)
{
	int	choice;
	int	diff;
	int	num;
	int	invert_a;

	choice = 0;
	num = (rots_b - rots_a);
	invert_a = (arr[3] + rots_a);
	if (invert_a > rots_b)
		diff = invert_a;
	else
		diff = rots_b;
	if (diff < num)
	{
		num = diff;
		choice = 2;
		if (diff == invert_a)
			choice = 1;
	}
	return (crying_shaking(rots_a, rots_b, arr, choice));
}

void	print_list_with_order(t_stack *st)
{
	t_stack	*temp;

	temp = st;
	while (temp != NULL)
	{
		ft_printf("\t%d\tpos: %d\n", temp->value, temp->pos);
		temp = temp->next;
	}
}
