/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:27:51 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/15 14:41:57 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	swap(t_lst_stack **lst)
{
	int	tmp;

	tmp = (*lst)->next->content;
	(*lst)->next->content = (*lst)->content;
	(*lst)->content = tmp;
	ft_printf("sa\n");
}

void	push_a(t_lst_stack **a, t_lst_stack **b)
{
	t_lst_stack	*tmp;

	if (!b)
		return ;
	tmp = (*b)->next;
	ft_stack_add_front(a, *b);
	*b = tmp;
	ft_printf("pa\n");
}

void	push_b(t_lst_stack **a, t_lst_stack **b)
{
	t_lst_stack	*tmp;

	if (!b)
		return ;
	tmp = (*b)->next;
	ft_stack_add_front(a, *b);
	*b = tmp;
	ft_printf("pb\n");
}

void	rotate(t_lst_stack **lst)
{
	t_lst_stack	*first;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	*lst = (*lst)->next;
	first->next = NULL;
	ft_stack_last(*lst)->next = first;
	ft_printf("ra\n");
}

void	rev_rotate(t_lst_stack **lst)
{
	t_lst_stack	*tmp;
	t_lst_stack	*prev_last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = ft_stack_last(*lst);
	prev_last = *lst;
	while (prev_last->next->next)
		prev_last = prev_last->next;
	prev_last->next = NULL;
	ft_stack_add_front(lst, tmp);
	ft_printf("rra\n");
}
