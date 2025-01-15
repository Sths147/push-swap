/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:43:08 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/15 14:48:27 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_lst_stack	**init_lst_a(char **av, size_t ac)
{
	t_lst_stack	**lst_a;
	char		**args;

	lst_a = malloc(sizeof(t_lst_stack *));
	if (!lst_a)
		return (NULL);
	*lst_a = NULL;
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			return (free(lst_a), NULL);
		args = ft_split(av[1], ' ');
		lst_a = check_and_fill_list(lst_a, args, 0);
		free(args);
	}
	else
		check_and_fill_list(lst_a, av, 1);
	return (lst_a);
}

int	check_list(t_lst_stack **a)
{
	t_lst_stack	*current;

	current = *a;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_bit_max(t_lst_stack **lst)
{
	t_lst_stack	*current;
	int			max;

	max = 32;
	while (max > 0)
	{
		current = *lst;
		while (current)
		{
			if (current->pos >> (max - 1) & 1)
				return (max);
			current = current->next;
		}
		max--;
	}
	return (0);
}
