/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:24:15 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/13 19:07:51 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_lst_stack
{
	int					content;
	unsigned int		pos;
	struct s_lst_stack	*next;
}				t_lst_stack;

# include "../libft/libft.h"
# include "parse.h"
# include "print_list.h"
# include "stack_lst_utils.h"
# include "ps_utils.h"

void	exit_error(void);
void	error_lists(t_lst_stack **a, t_lst_stack **b);
int		get_bit_max(t_lst_stack **lst);
void	sort_this(t_lst_stack **a, t_lst_stack **b, int max);

#endif 