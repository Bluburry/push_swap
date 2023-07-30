/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:19:05 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/04/03 20:19:19 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	validate_numbs(int start, int size, char **vals)
{
	int	j;

	while (++start < size)
	{
		if (!ft_check_alnum(vals[start]) || !over_checker(vals[start]))
			return (0);
		j = 0;
		while (++j < start)
			if (ft_atoi(vals[j]) == ft_atoi(vals[start]))
				return (0);
	}
	return (1);
}

int	over_checker(const char *str)
{
	int	number;
	int	i;

	number = 0;
	i = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		i *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && *str <= 57 && *str >= 48)
	{
		if (number > 214748364 || (number == 214748364 && *str - 48 > 7))
			return (0);
		number *= 10;
		number += *str - 48;
		str++;
	}
	return (1);
}

t_stack	*create_stack(int start, int size, char **vals)
{
	t_stack	*list;
	t_stack	*temp;

	list = NULL;
	while (++start < size)
	{
		temp = ft_lstnew(ft_atoi(vals[start]));
		ft_lstadd_back(&list, temp);
	}
	return (list);
}

int	check_ordered(t_stack *lst, t_stack *end)
{
	t_stack	*temp;

	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp->next != NULL && temp->next != end)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	find_smallest_pos(t_stack *lst)
{
	t_stack	*temp;
	int		smallest;
	int		small_i;

	smallest = smallest_val(lst);
	temp = lst;
	small_i = 0;
	while (temp != NULL)
	{
		if (temp->value == smallest)
			break ;
		small_i++;
		temp = temp->next;
	}
	return (small_i);
}
