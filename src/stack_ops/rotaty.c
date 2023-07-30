/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:44:21 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/03/30 18:44:22 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_stack **a, int from_r)
{
	t_stack	*save_first;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	save_first = *a;
	*a = (*a)->next;
	save_first->next = NULL;
	ft_lstadd_back(a, save_first);
	if (!from_r)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int from_r)
{
	t_stack	*save_first;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	save_first = *b;
	*b = (*b)->next;
	save_first->next = NULL;
	ft_lstadd_back(b, save_first);
	if (!from_r)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 1);
	rb(b, 1);
	if (print)
		ft_printf("rr\n");
}
