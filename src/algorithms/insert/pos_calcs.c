/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_calcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:12:47 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/07/24 17:12:48 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

int	biggest_pos(t_stack *st)
{
	t_stack	*temp;
	int		bigggie;
	int		count;
	int		pos;

	temp = st;
	bigggie = st->pos;
	count = 0;
	pos = 0;
	while (temp != NULL)
	{
		if (bigggie <= temp->pos)
		{
			bigggie = temp->pos;
			pos = count;
		}
		count++;
		temp = temp->next;
	}
	return (pos);
}

int	smallest_pos(t_stack *st, int size)
{
	t_stack	*tmp;
	int		count;
	int		n;
	int		sm;

	tmp = st;
	count = 0;
	n = 0;
	sm = st->pos;
	while (tmp != NULL)
	{
		if (sm >= tmp->pos)
		{
			sm = tmp->pos;
			n = count;
		}
		count++;
		tmp = tmp->next;
	}
	n++;
	if (n > size / 2)
		n -= size;
	return (n);
}

int	get_biggest_pos(t_stack *st)
{
	t_stack	*temp;
	int		beeg;

	beeg = 0;
	temp = st;
	while (temp != NULL)
	{
		if (temp->pos > beeg)
			beeg = temp->pos;
		temp = temp->next;
	}
	return (beeg);
}

int	find_fit(t_stack *st, int pos, int size)
{
	t_stack	*tmp;
	int		num;
	int		n;
	int		sm;

	tmp = st;
	num = 0;
	n = 0;
	sm = get_biggest_pos(st);
	while (tmp != NULL)
	{
		if (tmp->pos <= sm && tmp->pos > pos)
		{
			n = num;
			sm = tmp->pos;
		}
		num++;
		tmp = tmp->next;
	}
	n++;
	if (n > size / 2)
		n -= size;
	return (n);
}
