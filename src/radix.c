/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:07:44 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/13 19:17:31 by sithomas         ###   ########.fr       */
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

int	get_bit_max(t_lst_stack **lst)
{
	t_lst_stack	*current;
	int			max;
	
	max = 32;

	while(max > 0)
	{
		current = *lst;
		while (current)
		{	
			if (current->content >> (max - 1) & 1)
				return (max);
			current = current->next;
		}
		max--;
	}
	return (0);
}

void	sort_this(t_lst_stack **a, t_lst_stack **b, int max)
{
	int				i;
	size_t			j;
	size_t			size;
	int				tmp;
	int				ops;
	
	i = -1;
	size = ft_stack_size(*a);
	ops = 0;
	while (++i < max)
	{
		j = 0;
		while (j < size)
		{
			tmp = (*a)->content;
			if ((tmp >> i) & 1)
				rotate(a);
			else
				push(b, a);
			j++;
			ops++;
		}
		while (*b)
		{
			push(a, b);
			ops++;
		}
	}
	while (ft_stack_last(*a)->content < 0)
	{	
		rev_rotate(a);
		ops++;
	}
	// ft_printf("number ops: %d\n", ops);
}

/*
Comment classer byte par byte
*/