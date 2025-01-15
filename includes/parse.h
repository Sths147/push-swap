/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:27 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/15 14:55:27 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "push_swap.h"

t_lst_stack	**check_and_fill_list(t_lst_stack **lst, char **av, size_t index);
t_lst_stack	**init_lst_a(char **av, size_t ac);
int			check_list(t_lst_stack **a);
int			get_bit_max(t_lst_stack **lst);

#endif 