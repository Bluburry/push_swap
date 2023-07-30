/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:19:21 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/04/06 16:19:23 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	smallest_logic_quad(t_stack **a, t_stack **b, int smallest_pos)
{
	if (smallest_pos < 2)
		while (smallest_pos--)
			ra(a, 0);
	else
		while (smallest_pos++ < 4)
			rra(a, 0);
	pb(a, b, 1);
}

void	sort_quad(t_stack **a, t_stack **b)
{
	int	small_pos;

	small_pos = find_smallest_pos(*a);
	smallest_logic_quad(a, b, small_pos);
	sort_triple(a);
	pa(a, b, 1);
}

void	smallest_logic_penta(t_stack **a, t_stack **b, int smallest_pos)
{
	if (smallest_pos < 3)
		while (smallest_pos--)
			ra(a, 0);
	else
		while (smallest_pos++ < 5)
			rra(a, 0);
	pb(a, b, 1);
}

void	sort_penta(t_stack **a, t_stack **b)
{
	int	small_pos;

	small_pos = find_smallest_pos(*a);
	smallest_logic_penta(a, b, small_pos);
	sort_quad(a, b);
	pa(a, b, 1);
}
