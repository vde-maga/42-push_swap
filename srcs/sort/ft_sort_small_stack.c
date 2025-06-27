/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:57:10 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/27 17:13:13 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_sort_small_stack(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1 || ft_is_sorted(a))
		return (1);
	if (a->size == 2)
	{
		ft_sort_two(a);
		return (1);
	}
	if (a->size == 3)
	{
		ft_sort_three(a);
		return (1);
	}
	if (a->size == 4)
	{
		ft_sort_four(a, b);
		return (1);
	}
	if (a->size == 5)
	{
		ft_sort_five(a, b);
		return (1);
	}
	return (0);

}
