/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:44:26 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/03/30 18:44:27 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_stack **a, int from_r)
{
	int	temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp;
	if (!from_r)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int from_r)
{
	int	temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = temp;
	if (!from_r)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 1);
	sb(b, 1);
	if (print)
		ft_printf("ss\n");
}
