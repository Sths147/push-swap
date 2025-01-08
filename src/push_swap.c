/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:24:56 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/08 13:22:51 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
Program behaviour
	1. Parsing: initialise a chained list with all **argv elements inside
	and checks if args are in good format, if not, exits
	2. 
*/

int	main(int ac, char **av)
{
	t_lst_stack	**lst;
	
	if (ac < 2)
		exit (1);
	lst = malloc(sizeof(t_lst_stack *));
	if (!lst)
	{	
		write(2, "Error\n", 6);;
		free(lst);
		exit(1);
	}
	*lst = NULL;
	lst = check_and_fill_list(lst, av);
	if (!lst)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	print_lst_stack(lst);
	ft_stack_clear(lst, free);
	free(lst);
	return (0);
}

