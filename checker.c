/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:11:22 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/07/24 17:11:24 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack **a, t_stack **b, char *command)
{
	ft_lstclear(a);
	ft_lstclear(b);
	free(command);
	ft_printf("Error\n");
	exit (0);
}

int	switchboard(t_stack **a, t_stack **b, char *command)
{
	if (ft_cmpstr(command, "sa\n"))
		sa(a, 1);
	else if (ft_cmpstr(command, "sb\n"))
		sb(b, 1);
	else if (ft_cmpstr(command, "ss\n"))
		ss(a, b, 0);
	else if (ft_cmpstr(command, "pa\n"))
		pa(a, b, 0);
	else if (ft_cmpstr(command, "pb\n"))
		pb(a, b, 0);
	else if (ft_cmpstr(command, "ra\n"))
		ra(a, 1);
	else if (ft_cmpstr(command, "rb\n"))
		rb(b, 1);
	else if (ft_cmpstr(command, "rr\n"))
		rr(a, b, 0);
	else if (ft_cmpstr(command, "rra\n"))
		rra(a, 1);
	else if (ft_cmpstr(command, "rrb\n"))
		rrb(b, 1);
	else if (ft_cmpstr(command, "rrr\n"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	stack_checker(t_stack **a, t_stack **b)
{
	if ((*b) || !check_ordered(*a, NULL))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

void	checker_cont(int start, int size, char **arr)
{
	char	*command;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack(start, size, arr);
	command = get_next_line(0, 10);
	while (command != NULL)
	{
		if (!switchboard(&stack_a, &stack_b, command))
		{
			free_arr(arr, start, size);
			error(&stack_a, &stack_b, command);
		}
		free(command);
		usleep(100);
		command = get_next_line(0, 10);
	}
	stack_checker(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	free_arr(arr, start, size);
}

int	main(int argc, char **argv)
{
	char		**arr;
	int			size;
	int			start;

	size = argc;
	start = 0;
	if (argc < 2)
		return (0);
	arr = get_val_arr(argc, argv);
	if (argc == 2)
	{
		start = -1;
		size = arr_size(arr);
	}
	if (start + 1 == size)
		return (0);
	if (!validate_numbs(start, size, arr))
	{
		free_arr(arr, start, size);
		ft_printf("Error\n");
		return (0);
	}
	checker_cont(start, size, arr);
	return (0);
}
