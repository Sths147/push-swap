/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:24:15 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/08 13:16:49 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_lst_stack
{
	int					content;
	struct s_lst_stack	*next;
}				t_lst_stack;

# include "../libft/libft.h"
# include "parse.h"
# include "print_list.h"
# include "stack_lst_utils.h"

#endif 