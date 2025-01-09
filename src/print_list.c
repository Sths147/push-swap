/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:23:01 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/09 11:38:44 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_list.h"

void	print_lst_stack(t_lst_stack **lst)
{
	t_lst_stack	*current;
	int	i;

	if (!lst)
		return ;
	current = *lst;
	i = 1;
	while (current)
	{
		ft_printf("%d: %i\n", i, current->content);
		i++;
		current = current->next;
	}
}