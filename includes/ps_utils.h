/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:27:08 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/09 16:21:19 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_UTILS_H
# define PS_UTILS_H

# include "push_swap.h"

void	swap(t_lst_stack **lst);
void	ss(t_lst_stack **a, t_lst_stack **b);
void	push(t_lst_stack **a, t_lst_stack **b);
void	rotate(t_lst_stack **lst);
void	rev_rotate(t_lst_stack **lst);

#endif 