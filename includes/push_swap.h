/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:52:55 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/18 14:55:01 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					rank;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack
{
	t_stack_node		*top;
	t_stack_node		*bottom;
	int	size;
}						t_stack;

/*
 * =================
 * ===== Utils =====
 * =================
*/
char	**ft_split(char const *s, char c);
void	ft_exit_error(void);
void	ft_stack_init(t_stack *stack);
void	ft_parse_args(char **args, t_stack *stack_a, int should_free);
long	ft_atol(const char *str);


#endif
