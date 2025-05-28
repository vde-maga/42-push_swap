/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:44:19 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/28 15:42:18 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (*a != NULL && (*a)->next != NULL)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
		ft_printf("sa\n");
	}
}

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (*b != NULL && (*b)->next != NULL)
	{
		first = *b;
		second - (*b)->next;
		first->next = second->next;
		second->next = first;
		*b = second;
		ft_printf("sb\n");
	}
}
