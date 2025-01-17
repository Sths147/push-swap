/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:07:44 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/17 13:47:07 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_five(t_lst_stack **a, t_lst_stack **b);
static void	minisort(t_lst_stack **a);
static void	push_four(t_lst_stack **a, t_lst_stack **b, unsigned int pos);

/*
If the list is made of more than 5 elements, it:
considers each pos into binary
until the max rank is sorted, sorts every elements
with radix algorithm applied to binary
*/

void	sort_this(t_lst_stack **a, t_lst_stack **b, int max)
{
	int		i;
	size_t	j;
	size_t	size;
	int		tmp;

	i = -1;
	size = ft_stack_size(*a);
	while (++i < max)
	{
		j = 0;
		while (j < size)
		{
			tmp = (*a)->pos;
			if ((tmp >> i) & 1)
				rotate(a);
			else
				push_b(b, a);
			j++;
		}
		while (*b)
			push_a(a, b);
	}
}

/*
If list a is composed of maximum 5 elements,
we cuts the list into a list of 3 elements, sort it
and adds the firsts elements
*/
void	short_sort(t_lst_stack **a, t_lst_stack **b)
{
	size_t	size;

	size = ft_stack_size(*a);
	if (size <= 3)
		return (minisort(a));
	else if (size == 4)
		push_four(a, b, 0);
	else if (size == 5)
		push_five(a, b);
	minisort(a);
	if (size == 4)
		(push_a(a, b));
	else
	{
		push_a(a, b);
		push_a(a, b);
	}
}

/*
List composed of max 3 elements is sorted
*/
static void	minisort(t_lst_stack **a)
{
	if (ft_stack_size(*a) == 2)
		return (swap(a));
	if (((*a)->pos > (*a)->next->pos) && ((*a)->pos > (*a)->next->next->pos))
		rotate(a);
	if (((*a)->next->pos > (*a)->next->next->pos)
		&& ((*a)->next->pos > (*a)->pos))
		rev_rotate(a);
	if ((*a)->pos > (*a)->next->pos)
		swap(a);
}

/*
if list is 4 elements long:
1. Gets smallest element
2. push_b
*/
static void	push_four(t_lst_stack **a, t_lst_stack **b, unsigned int indicator)
{
	if ((*a)->pos == indicator)
		return (push_b(b, a));
	if ((*a)->next->pos == indicator)
	{
		swap(a);
		push_b(b, a);
		return ;
	}
	if ((*a)->next->next->pos == indicator)
	{
		rotate(a);
		swap(a);
		push_b(b, a);
		return ;
	}
	if ((*a)->next->next->next->pos == indicator)
	{
		rev_rotate(a);
		push_b(b, a);
		return ;
	}
}

/*
if list is 5 elements long
1. Gets 2 smallest elements
2. push b
*/
static void	push_five(t_lst_stack **a, t_lst_stack **b)
{
	if ((*a)->pos == 0)
		push_b(b, a);
	else if ((*a)->next->pos == 0)
	{
		swap(a);
		push_b(b, a);
	}
	else if ((*a)->next->next->pos == 0)
	{
		rotate(a);
		swap(a);
		push_b(b, a);
	}
	else if ((*a)->next->next->next->pos == 0)
	{
		rev_rotate(a);
		rev_rotate(a);
		push_b(b, a);
	}
	else
	{
		rev_rotate(a);
		push_b(b, a);
	}
	push_four(a, b, 1);
}
