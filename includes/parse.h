/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:27 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/16 12:46:49 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "push_swap.h"

t_lst_stack	**init_lst_a(char **av, size_t ac);
int			check_list(t_lst_stack **a);
int			get_bit_max(t_lst_stack **lst);
int			check_args(char **av, size_t index);

#endif 