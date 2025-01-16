/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:26:48 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/16 11:34:37 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lst_utils.h"

unsigned int	ft_stack_size(t_lst_stack *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_lst_stack	*ft_stack_new(int content)
{
	t_lst_stack	*new_lst;

	new_lst = (t_lst_stack *)malloc(sizeof(t_lst_stack));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}

t_lst_stack	*ft_stack_last(t_lst_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_stack_clear(t_lst_stack **lst, void (*del)(void *))
{
	t_lst_stack	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		del(*lst);
		*lst = tmp;
	}
	lst = NULL;
}

void	ft_stack_add_back(t_lst_stack **lst, t_lst_stack *new)
{
	t_lst_stack	*last;

	if (*lst == NULL || lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_stack_last(*lst);
	last->next = new;
}
