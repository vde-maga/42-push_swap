/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:38:10 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/28 15:50:24 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = ft_stacklast(*a);
	*a = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	last = ft_stacklast(*b);
	*b = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("rb\n");
}

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	second_last = NULL;
	while (last-> != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last != NULL)
	{
		second_last->next = NULL;
		last->next = *a;
		*a = last
	}
	ft_printf("rra\n");
}
