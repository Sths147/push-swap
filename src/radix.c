/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:07:44 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/15 14:50:25 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Todo :
Int en binaire : 4 bytes
1. Trouver le 1 le plus a gauche de l'ensemble de la liste (MAX)
2. pour chaque élément, je bouge de i (i compris entre 0 et MAX) et
		* Si j'ai un 1, j'envoie sur b
		* sinon, je rotate
	lorsque j'ai fini, je push tout sur a
	je recommence (MAX) fois
*/
static void	push_five(t_lst_stack **a, t_lst_stack **b);
static void	minisort(t_lst_stack **a);
static void	push_four(t_lst_stack **a, t_lst_stack **b, unsigned int pos);

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

void	short_sort(t_lst_stack **a, t_lst_stack **b)
{
	size_t	size;

	size = ft_stack_size(*a);
	if (size <= 3)
		return (minisort(a));
	if (size == 4)
		push_four(a, b, 0);
	if (size == 5)
		push_five(a, b);
	minisort(a);
	if (size == 4)
		return (push_a(a, b));
	else
	{
		push_a(a, b);
		push_a(a, b);
	}
}

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

static void	push_four(t_lst_stack **a, t_lst_stack **b, unsigned int indicator)
{
	if ((*a)->pos == indicator)
		return (push_b(b, a));
	if ((*a)->next->pos == indicator)
		return (swap(a), push_b(b, a));
	if ((*a)->next->next->pos == indicator)
		return (rotate(a), swap(a), push_b(b, a));
	if ((*a)->next->next->next->pos == indicator)
		return (rev_rotate(a), push_b(b, a));
}

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
