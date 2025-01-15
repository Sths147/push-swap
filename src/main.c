/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:24:56 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/15 15:51:42 by sithomas         ###   ########.fr       */
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
	t_lst_stack	**a;
	t_lst_stack	**b;

	if (ac < 2)
		exit (1);
	a = init_lst_a(av, ac);
	if (!a)
		exit_error();
	b = malloc(sizeof(t_lst_stack *));
	if (!b)
		error_lists(a, b);
	if (check_list(a))
		return (free_lists(a, b), 0);
	if (ft_stack_size(*a) < 6)
		short_sort(a, b);
	else
		sort_this(a, b, get_bit_max(a));
	free_lists(a, b);
	return (0);
}
