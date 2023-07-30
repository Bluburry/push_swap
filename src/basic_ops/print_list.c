/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:28:21 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/04/04 18:28:22 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	list_a(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (temp->next != NULL)
	{
		ft_printf("\t%d\n", temp->value);
		temp = temp->next;
	}
	ft_printf("\t%d\n", temp->value);
}

void	list_b(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (temp->next != NULL)
	{
		ft_printf("\t\t%d\n", temp->value);
		temp = temp->next;
	}
	ft_printf("\t\t%d\n", temp->value);
}

void	list_two_lists(t_stack *a, t_stack *b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = a;
	temp_b = b;
	while (temp_a->next != NULL && temp_b->next != NULL)
	{
		ft_printf("\t%d\t%d\n", temp_a->value, temp_b->value);
		temp_a = temp_a->next;
		temp_b = temp_b->next;
	}
	ft_printf("\t%d\t%d\n", temp_a->value, temp_b->value);
	if (temp_a->next == NULL && temp_b->next != NULL)
	{
		temp_b = temp_b->next;
		list_b(temp_b);
	}
	else if (temp_a->next != NULL && temp_b->next == NULL)
	{
		temp_a = temp_a->next;
		list_a(temp_a);
	}
}

void	list_stacks(t_stack *a, t_stack *b)
{
	if (a != NULL && b != NULL)
		list_two_lists(a, b);
	else if (a != NULL && b == NULL)
		list_a(a);
	else if (a == NULL && b != NULL)
		list_b(b);
	ft_printf("\t-\t-\n\ta\tb\n");
}
