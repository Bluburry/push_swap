/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:43:58 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/03/30 18:44:10 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (*a == NULL && *b == NULL)
		return ;
	temp = *b;
	(*b) = (*b)->next;
	ft_lstadd_front(a, temp);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	(*a) = (*a)->next;
	ft_lstadd_front(b, temp);
	if (print)
		ft_printf("pb\n");
}
