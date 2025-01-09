/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lst_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:29:56 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/09 10:53:11 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_LST_UTILS_H
# define STACK_LST_UTILS_H

#include "push_swap.h"

int	ft_stack_size(t_lst_stack *lst);
t_lst_stack	*ft_stack_new(int content);
t_lst_stack	*ft_stack_last(t_lst_stack *lst);
void	ft_stack_clear(t_lst_stack **lst, void (*del)(void *));
void	ft_stack_add_back(t_lst_stack **lst, t_lst_stack *new);
void	ft_stack_add_front(t_lst_stack **lst, t_lst_stack *new);

#endif