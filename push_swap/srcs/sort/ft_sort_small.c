/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:37:19 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/04 18:05:11 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sortlist_size2(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap('a', stack_a, stack_b);
}

void	ft_sortlist_size3(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	middle;
	int	last;

	first = (*stack_a)->value;
	middle = (*stack_a)->next->value;
	last = (*stack_a)->next->next->value;
	if (first > middle && first > last)
		ft_rotate('a', stack_a, stack_b);
	else if (middle > last && middle > first)
		ft_reverse_rotate('a', stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_swap('a', stack_a, stack_b);
}

void	ft_sortlist_size4(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_get_min(stack_a);
	if ((*stack_a)->next->next->next->value == min)
		ft_reverse_rotate('a', stack_a, stack_b);
	while ((*stack_a)->value != min)
		ft_rotate('a', stack_a, stack_b);
	ft_push('b', stack_b, stack_a);
	ft_sortlist_size3(stack_a, stack_b);
	ft_push('a', stack_a, stack_b);
}

void	ft_sortlist_size5(t_stack **stack_a, t_stack **stack_b)
{
	int	to_push;
	int	len;
	int	pos;

	len = 5;
	to_push = 2;
	while (to_push--)
	{
		pos = ft_get_pos_min(*stack_a);
		if (pos <= len / 2)
			while (pos-- > 0)
				ft_rotate('a', stack_a, stack_b);
		else
			while (pos++ < len)
				ft_reverse_rotate('a', stack_a, stack_b);
		ft_push('b', stack_b, stack_a);
		len--;
	}
	ft_sortlist_size3(stack_a, stack_b);
	if ((*stack_b)->value < (*stack_b)->next->value)
		ft_swap('b', NULL, stack_b);
	ft_push('a', stack_a, stack_b);
	ft_push('a', stack_a, stack_b);
}

void	ft_sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_sortlist_size2(stack_a, stack_b);
	else if (size == 3)
		ft_sortlist_size3(stack_a, stack_b);
	else if (size == 4)
		ft_sortlist_size4(stack_a, stack_b);
	else if (size == 5)
		ft_sortlist_size5(stack_a, stack_b);
}
