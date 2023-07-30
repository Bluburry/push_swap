/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_squared.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:08:20 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/04/06 20:08:23 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	smallest_val(t_stack *lst)
{
	int		small;
	t_stack	*temp;

	temp = lst;
	small = temp->value;
	while (temp != NULL)
	{
		if (small >= temp->value)
			small = temp->value;
		temp = temp->next;
	}
	return (small);
}

int	biggest_val(t_stack *lst)
{
	int		bigggie;
	t_stack	*temp;

	temp = lst;
	bigggie = temp->value;
	while (temp != NULL)
	{
		if (bigggie <= temp->value)
			bigggie = temp->value;
		temp = temp->next;
	}
	return (bigggie);
}

int	check_reverse_ordered(t_stack *lst, t_stack *end)
{
	t_stack	*temp;

	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp->next != NULL && temp->next != end)
	{
		if (temp->value < temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	find_biggest_pos(t_stack *lst)
{
	t_stack	*temp;
	int		biggest_pos;
	int		biggest;

	biggest = biggest_val(lst);
	temp = lst;
	biggest_pos = 0;
	while (temp != NULL)
	{
		if (temp->value == biggest)
			break ;
		biggest_pos++;
		temp = temp->next;
	}
	return (biggest_pos);
}
