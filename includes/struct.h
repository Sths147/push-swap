/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:55:44 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/15 14:55:58 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_lst_stack
{
	int					content;
	unsigned int		pos;
	struct s_lst_stack	*next;
}				t_lst_stack;
