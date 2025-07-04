/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:45:39 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/04 18:05:45 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(char c, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*last;

	if ((c == 'a') && (*stack_a) && (*stack_a)->next)
	{
		temp = *stack_a;
		first = (*stack_a)->next;
		last = ft_get_last(stack_a);
		last->next = temp;
		temp->next = NULL;
		*stack_a = first;
		write(1, "ra\n", 3);
	}
	else if ((c == 'b') && (*stack_b) && (*stack_b)->next)
	{
		temp = *stack_b;
		first = (*stack_b)->next;
		last = ft_get_last(stack_b);
		last->next = temp;
		temp->next = NULL;
		*stack_b = first;
		write(1, "rb\n", 3);
	}
}

void	ft_reverse_rotate(char c, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*second_last;
	t_stack	*last;

	if ((c == 'a' || c == 'r') && (*stack_a) && (*stack_a)->next)
	{
		last = ft_get_last(stack_a);
		second_last = ft_get_second_last(stack_a);
		second_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		write(1, "rra\n", 4);
	}
	if ((c == 'b' || c == 'r') && (*stack_b) && (*stack_b)->next)
	{
		last = ft_get_last(stack_b);
		second_last = ft_get_second_last(stack_b);
		second_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		write(1, "rrb\n", 4);
	}
}
