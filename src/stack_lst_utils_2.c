/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lst_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:42:51 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/09 10:53:06 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lst_utils.h"

void	ft_stack_add_front(t_lst_stack **lst, t_lst_stack *new)
{
	new->next = *lst;
	*lst = new;
}