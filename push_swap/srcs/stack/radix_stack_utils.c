/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:32:24 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/03 15:50:54 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_get_bits(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	int		bits;

	temp = *stack;
	max = temp->index;
	bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
