/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:24:56 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/10 18:26:39 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lst_stack	**init_lst_a(char **av);


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
	a = init_lst_a(av);
	if (!a)
		exit_error();
	b = malloc(sizeof(t_lst_stack *));
	if (!b)
		error_lists(a, b);
	write(1, "Stack a:\n", 9);
	print_lst_stack(a);
	write(1, "Stack b:\n", 9);
	print_lst_stack(b);
	ft_printf("MAX: %d\n", get_bit_max(a));
	sort_this(a, b, get_bit_max(a));
	write(1, "Stack a:\n", 9);
	print_lst_stack(a);
	write(1, "Stack b:\n", 9);
	print_lst_stack(b);
	ft_stack_clear(a, free);
	ft_stack_clear(b, free);
	return (0);
}

static t_lst_stack	**init_lst_a(char **av)
{
	t_lst_stack	**lst_a;

	lst_a = malloc(sizeof(t_lst_stack *));
	if (!lst_a)
		return (NULL);
	*lst_a = NULL;
	lst_a = check_and_fill_list(lst_a, av);
	return(lst_a);
}

