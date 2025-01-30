/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:53:19 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/30 16:56:49 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int			is_not_int(const char *nptr);
static int			is_duplicate(char **av, size_t index, int nbr, int checker);

/*
For every argument:
1. Checks if argument is int
2. Checks if argument already exists in char **
*/

int	check_args(char **av, size_t index)
{
	int	checker;

	if (index == 0)
		checker = 0;
	else
		checker = 1;
	while (av[index])
	{
		if (is_not_int(av[index]))
			return (1);
		if (is_duplicate(av, index, ft_atoi(av[index]), checker))
			return (1);
		index++;
	}
	return (0);
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
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	if (ft_strlen(nptr) > 11)
		return (1);
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	if ((nptr[i] < '0') || (nptr[i] > '9'))
		return (1);
	while (nptr[i])
	{
		if ((nptr[i] < '0') || (nptr[i] > '9'))
			return (1);
		result = result * 10 + (nptr[i++] - 48);
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		return (1);
	return (0);
}
/*
For every int I have, I check if the same int already exists in the char **
*/

static int	is_duplicate(char **av, size_t index, int nbr, int checker)
{
	size_t	j;

	if (!*av[checker])
		return (1);
	j = checker;
	while (av[j])
	{
		if (j == index)
		{
			j++;
			continue ;
		}
		if (nbr == ft_atoi(av[j]))
			return (1);
		j++;
	}
	return (0);
}

/*
Function gets maximum rank, in binary (max == 32 for int)
existing for all ints in the list 
*/
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
