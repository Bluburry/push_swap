/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:44:14 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/03/30 18:44:15 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_stack **a, int from_r)
{
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_lstadd_front(a, ft_lstlast(*a));
	temp->next = NULL;
	if (!from_r)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int from_r)
{
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_lstadd_front(b, ft_lstlast(*b));
	temp->next = NULL;
	if (!from_r)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 1);
	rrb(b, 1);
	if (print)
		ft_printf("rrr\n");
}
