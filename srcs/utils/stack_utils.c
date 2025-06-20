/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:32:08 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/20 15:49:48 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	ft_parse_args(char **args, t_stack *stack_a, int should_free)
{
	int		i;
	long	temp_val;

	i = 0;
	while (args[i])
	{
		temp_val = ft_atol(args[i]);
		if (!ft_str_just_number(args[i]) || ft_has_duplicate(stack_a,
				(int)temp_val))
		{
			ft_free_stack(stack_a);
			if (should_free)
				ft_free_split(args);
			ft_exit_error();
		}
		i++;
	}
}

int	ft_has_duplicate(t_stack *stack_a, int value)
{
	t_stack_node	*current;

	current = stack_a->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_free_resources(t_stack *stack_a, t_stack *stack_b, char **args, int should_free)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	if (should_free)
		ft_free_split(args);
}
