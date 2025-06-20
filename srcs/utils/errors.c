/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:23:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/20 15:47:03 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_exit_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}
