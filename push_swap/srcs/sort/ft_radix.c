/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:17:50 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/04 18:05:03 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int		max_bits;
	int		bits;
	int		i;
	int		stack_size;
	t_stack	*temp;

	bits = -1;
	i = 0;
	stack_size = ft_get_stack_size(stack_a);
	ft_put_first_index(stack_a);
	max_bits = ft_get_bits(stack_a);
	while (!ft_is_sorted(stack_a) && ++bits < max_bits)
	{
		i = 0;
		while (i++ < stack_size)
		{
			temp = *stack_a;
			if (((temp->index >> bits) & 1) == 1)
				ft_rotate('a', stack_a, stack_b);
			else
				ft_push('b', stack_b, stack_a);
		}
		while (*stack_b)
			ft_push('a', stack_a, stack_b);
	}
}
