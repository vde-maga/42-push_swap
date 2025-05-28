/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.co      +#+  +:+    m> +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:22:14 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/28 15:41:55 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/includes/libft.h"

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}					t_stack;

//===========
// OPERATIONS
//===========

// SWAP
void	sa(t_stack **a);

#endif
