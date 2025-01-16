/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:11:32 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/16 11:33:33 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_lists(t_lst_stack **a, t_lst_stack **b)
{
	if (a)
	{	
		ft_stack_clear(a, free);
		free(a);
	}
	if (b)
	{
		ft_stack_clear(b, free);
		free(b);
	}
}

void	error_lists(t_lst_stack **a, t_lst_stack **b)
{
	free_lists(a, b);
	exit_error();
}

void	free_tab(char **tab)
{
	size_t	index;

	index = 0;
	while (tab[index])
		free(tab[index++]);
	free(tab);
}
