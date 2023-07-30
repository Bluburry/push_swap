/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:00:20 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/04/11 16:00:53 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->next != NULL && (*a)->value > (*a)->next->value)
		sa(a, 0);
}

void	first_bigger(t_stack **a)
{
	if ((*a)->next->value > (*a)->next->next->value)
	{
		ra(a, 0);
		sa(a, 0);
	}
	else if ((*a)->next->value < (*a)->next->next->value)
	{
		if ((*a)->value < (*a)->next->next->value)
			sa(a, 0);
		else
		{
			rra(a, 0);
			rra(a, 0);
		}
	}
}

void	second_bigger(t_stack **a)
{
	if ((*a)->next->value > (*a)->next->next->value)
	{
		rra(a, 0);
		if ((*a)->value > (*a)->next->value)
			sa(a, 0);
	}
}

void	sort_triple(t_stack **a)
{
	if ((*a)->value < (*a)->next->value 
		&& (*a)->next->value < (*a)->next->next->value)
		return ;
	if ((*a)->value > (*a)->next->value)
		first_bigger(a);
	else if ((*a)->value < (*a)->next->value)
		second_bigger(a);
}
