/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:13:05 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/07/24 17:13:07 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	**get_val_arr(int argc, char **argv)
{
	if (argc > 2)
		return (argv);
	return (ft_split(argv[1], ' '));
}

int	arr_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
		i++;
	return (i);
}

void	free_arr(char **arr, int start, int size)
{
	int	i;

	if (start == 0)
		return ;
	i = -1;
	while (++i < size)
		free(arr[i]);
	free(arr);
}
