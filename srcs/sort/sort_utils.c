/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:48:53 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/27 16:56:19 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_stack_node	*current;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->rank > current->next->rank)
			return (0);
		current = current->next;
	}
	return (1);
}
