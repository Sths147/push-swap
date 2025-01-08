/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:53:19 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/08 14:46:25 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_not_int(const char *nptr);
static int	is_duplicate(t_lst_stack **lst, int nbr);

/*
For every argument: 
1. Checks if argument is int
2. Checks if argument already exists in list
3. Adds argument back into list
*/

t_lst_stack	**check_and_fill_list(t_lst_stack **lst, char **av)
{
	size_t	i;
	t_lst_stack	*new;
	
	i = 1;
	while (av[i])
	{
		if (is_not_int(av[i]) || is_duplicate(lst, ft_atoi(av[i])))
		{	
			ft_stack_clear(lst, free);
			return (NULL);
		}
		new = ft_stack_new(ft_atoi(av[i]));
		if (!new)
		{	
			ft_stack_clear(lst, free);
			return (NULL);
		}
		ft_stack_add_back(lst, new);
		i++;
	}
	return (lst);
}
/*
Checks if a char is not an int : 
- If first char is different from '-' or digit
- If chars are different than digits
- if nbr exceeds int size 
*/

static int	is_not_int(const char *nptr)
{
	size_t	i;
	long	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i])
	{
		 if ((nptr[i] < '0') || (nptr[i] > '9'))
			return(1);
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	if ((sign * result) > INT_MAX || (sign * result) < INT_MIN)
		return(1);
	return (0);
}
/*
For every int I have, I check if the same int already exists in the list
*/
static int	is_duplicate(t_lst_stack **lst, int nbr)
{
	t_lst_stack	*tmp;

	if (!lst || !*lst)
		return (0);
	tmp = *lst;
	while (tmp)
	{
		if (tmp->content == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}