/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:11:32 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/09 11:28:37 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_lists(t_lst_stack **a, t_lst_stack **b)
{
	ft_stack_clear(a, free);
	ft_stack_clear(b, free);
	write(2, "Error\n", 6);
	exit(1);
}