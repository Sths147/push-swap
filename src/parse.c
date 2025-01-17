/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:43:08 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/17 14:00:30 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_lst_stack	**fill_list(t_lst_stack **lst, char **av, size_t index);
static void			fill_pos(t_lst_stack **lst);
static unsigned int	getpos(int myint, t_lst_stack **lst, unsigned int size);

/*
Initiates the list depending if the list is displayed as
a single argument or different arguments
*/

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
		if (check_args(args, 0))
			return (free_tab(args), free(lst_a), NULL);
		lst_a = fill_list(lst_a, args, 0);
		free_tab(args);
	}
	else
	{
		if (check_args(av, 1))
			return (free(lst_a), NULL);
		lst_a = fill_list(lst_a, av, 1);
	}
	return (lst_a);
}
/*
If the arguments are only ints,
creates the list with 1 argument per node
*/

static t_lst_stack	**fill_list(t_lst_stack **lst, char **av, size_t index)
{
	t_lst_stack	*new;

	while (av[index])
	{
		new = ft_stack_new(ft_atoi(av[index]));
		if (!new)
		{
			ft_stack_clear(lst, free);
			free(lst);
			return (NULL);
		}
		ft_stack_add_back(lst, new);
		index++;
	}
	if (lst)
		fill_pos(lst);
	return (lst);
}

/*
Checks if list is already sorted
*/
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

/*
Gets the position of an element compared to the whole list[...
*/
static unsigned int	getpos(int myint, t_lst_stack **lst, unsigned int size)
{
	t_lst_stack	*current;

	current = *lst;
	while (current)
	{
		if (current->content > myint)
			size--;
		current = current->next;
	}
	return (size);
}

/*
...]and fills the list with it
*/
static void	fill_pos(t_lst_stack **lst)
{
	t_lst_stack		*current;
	unsigned int	size;

	size = ft_stack_size(*lst) - 1;
	current = *lst;
	while (current)
	{
		current->pos = getpos(current->content, lst, size);
		current = current->next;
	}
}
