/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:24:15 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/16 15:25:18 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "struct.h"
# include "../libft/libft.h"
# include "stack_lst_utils.h"
# include "parse.h"
# include "ps_utils.h"

void	exit_error(void);
void	error_lists(t_lst_stack **a, t_lst_stack **b);
void	free_lists(t_lst_stack **a, t_lst_stack **b);
int		get_bit_max(t_lst_stack **lst);
void	sort_this(t_lst_stack **a, t_lst_stack **b, int max);
void	short_sort(t_lst_stack **a, t_lst_stack **b);
int		check_list(t_lst_stack **a);
void	free_tab(char **tab);

#endif 