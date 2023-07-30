/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:28:49 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/07/10 16:28:50 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	set_pos(t_stack **stack)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		i;

	temp1 = *stack;
	while (temp1 != NULL)
	{
		i = 0;
		temp2 = *stack;
		while (temp2 != NULL)
		{
			if (temp1->value > temp2->value)
				i++;
			temp2 = temp2->next;
		}
		temp1->pos = i;
		temp1 = temp1->next;
	}
}

int	is_bigger(t_stack *st, int val)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp != NULL)
	{
		if (val < tmp->pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_smaller(t_stack *st, int val)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp != NULL)
	{
		if (val > tmp->pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
