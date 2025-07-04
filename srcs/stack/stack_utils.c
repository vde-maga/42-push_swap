/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:35:08 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/04 18:02:18 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_get_stack_size(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_stack	*ft_get_last(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_stack	*ft_get_second_last(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}

int	ft_get_min(t_stack **stack)
{
	t_stack	*temp;
	int		min;

	temp = *stack;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}
