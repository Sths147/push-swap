/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:53:19 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/07 15:13:11 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_not_int(const char *nptr);
static int	is_duplicate(t_list **lst, int nbr);
static t_list	*ft_lstnew_int(int nbr);

/*
For every argument: 
1. Checks if argument is int
2. Checks if argument already exists in list
3. Adds argument back into list
*/

t_list	**check_and_fill_list(t_list **lst, char **av)
{
	size_t	i;
	t_list	*new;
	
	i = 1;
	while (av[i])
	{
		printf("%s\n", av[i]);
		if (is_not_int(av[i]) || is_duplicate(lst, ft_atoi(av[i])))
		{	
			ft_lstclear(lst, free);
			return (NULL);
		}
		new = ft_lstnew_int(ft_atoi(av[i]));
		if (!new)
		{	
			ft_lstclear(lst, free);
			return (NULL);
		}
		ft_lstadd_back(lst, new);
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
static int	is_duplicate(t_list **lst, int nbr)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return (0);
	tmp = *lst;
	while (tmp)
	{
		if (*(int *)(tmp->content) == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static t_list	*ft_lstnew_int(int nbr)
{
	int		*ptr;
	t_list	*new;

	ptr = malloc(sizeof(int));
	if (!ptr)
		return (NULL);
	*ptr = nbr;
	new = ft_lstnew(ptr);
	if (!new)
	{
		free(ptr);
		return (NULL);
	}
	return (new);
}
