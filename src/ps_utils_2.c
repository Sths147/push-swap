/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:29:22 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/13 18:23:40 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	ss(t_lst_stack **a, t_lst_stack **b)
{
	swap(a);
	swap(b);
}

void	rr(t_lst_stack **a, t_lst_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_lst_stack **a, t_lst_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
