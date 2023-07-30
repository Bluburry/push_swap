/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:28:36 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/07/10 16:28:38 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	both_pos(int rots_a, int rots_b, int *arr)
{
	if (rots_a > rots_b)
	{
		arr[0] = rots_a - rots_b;
		arr[2] = rots_a - arr[0];
	}
	else if (rots_a < rots_b)
	{
		arr[1] = rots_b - rots_a;
		arr[2] = rots_b - arr[1];
	}
	else if (rots_a == rots_b)
		arr[2] = rots_a;
}

void	both_negative(int rots_a, int rots_b, int *arr)
{
	if (rots_a > rots_b)
	{
		arr[1] = rots_b - rots_a;
		arr[2] = rots_b - (rots_b - rots_a);
	}
	else if (rots_a < rots_b)
	{
		arr[0] = rots_a - rots_b;
		arr[2] = rots_a - (rots_a - rots_b);
	}
	else if (rots_a == rots_b)
		arr[2] = rots_a;
}

void	shaking(int choice, int rots_a, int rots_b, int *arr)
{
	if (choice == 0)
	{
		arr[0] = rots_a;
		arr[1] = rots_b;
	}
	else if (choice == 1)
	{
		arr[0] = (rots_a - arr[3]) - rots_b;
		arr[2] = rots_b;
	}
	else if (choice == 2)
	{
		arr[1] = rots_b - (rots_a - arr[3]);
		arr[2] = (rots_a - arr[3]);
	}
	else if (choice == 3)
	{
		arr[1] = (arr[4] + rots_b) - rots_a;
		arr[2] = rots_a;
	}
	else if (choice == 4)
	{
		arr[0] = rots_a - (arr[4] + rots_b);
		arr[2] = (arr[4] + rots_b);
	}
}

void	crying(int choice, int rots_a, int rots_b, int *arr)
{
	if (choice == 0)
	{
		arr[0] = rots_a;
		arr[1] = rots_b;
	}
	else if (choice == 1)
	{
		arr[0] = (arr[3] + rots_a) - rots_b;
		arr[2] = rots_b;
	}
	else if (choice == 2)
	{
		arr[1] = rots_b - (arr[3] + rots_a);
		arr[2] = (arr[3] + rots_a);
	}
	else if (choice == 3)
	{
		arr[1] = (rots_b - arr[4]) - rots_a;
		arr[2] = rots_a;
	}
	else if (choice == 4)
	{
		arr[0] = rots_a - (rots_b - arr[4]);
		arr[2] = (rots_b - arr[4]);
	}
}

void	calc_handler(t_stack **a, t_stack **b, int pos, int *arr)
{
	int	rots_a;
	int	rots_b;

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	rots_a = calc_a_rots(*a, pos, arr[3]);
	rots_b = calc_b_rots(*b, pos, arr[4]);
	if ((rots_a == 0 && rots_b == 0) || (rots_a != 0 && rots_b == 0)
		|| (rots_a == 0 && rots_b != 0))
	{
		arr[0] = rots_a;
		arr[1] = rots_b;
	}
	else if (rots_a > 0 && rots_b > 0)
		both_pos(rots_a, rots_b, arr);
	else if (rots_a < 0 && rots_b < 0)
		both_negative(rots_a, rots_b, arr);
	else if (rots_a > 0 && rots_b < 0)
		shaking(shaking_and_crying(rots_a, rots_b, arr),
			rots_a, rots_b, arr);
	else if (rots_a < 0 && rots_b > 0)
		crying(crying_and_shaking(rots_a, rots_b, arr),
			rots_a, rots_b, arr);
}
