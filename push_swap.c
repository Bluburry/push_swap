/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:02:06 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/07/10 16:35:29 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switchboard(t_stack **a, t_stack **b, int nums)
{
	if (nums == 2)
		sort_two(a);
	else if (nums == 3)
		sort_triple(a);
	else if (nums == 4)
		sort_quad(a, b);
	else if (nums == 5)
		sort_penta(a, b);
	else
		insert_sort(a, b);
}

void	start_sort(int argc, int start, int size, char **arr)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = size;
	if (size == argc)
		i = argc - 1;
	stack_a = create_stack(start, size, arr);
	if (!check_ordered(stack_a, NULL))
		switchboard(&stack_a, &stack_b, i);
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
	start_sort(argc, start, size, arr);
	return (0);
}
