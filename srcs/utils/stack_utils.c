/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:32:08 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/18 15:04:52 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_stack_init(t_stack *stack)
{
	if (!stack)
		return;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	ft_parse_args(char **args, t_stack *stack_a, int should_free)
{
	int	i;
	long	temp_val;

	i = 0;
	while (args[i])
	{
		temp_val = ft_atol(args[i]);
		if (!is_number_str(args[i]) || has_duplicate(stack_a, (int)temp_val))
		{
			free_stack(stack_a);
			if (should_free)
				free_split(args);
			exit_error();
		}
		i++;
	}
}
