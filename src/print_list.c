/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:23:01 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/08 14:45:51 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_list.h"

void	print_lst_stack(t_lst_stack **lst)
{
	t_lst_stack	*current;
	int	i;

	current = *lst;
	i = 1;
	while (current)
	{
		ft_printf("Element nb %d: %i\n", i, current->content);
		i++;
		current = current->next;
	}
}