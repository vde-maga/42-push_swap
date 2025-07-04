/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:01:36 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/04 18:04:27 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_get_pos_min(t_stack *a)
{
	int	pos;
	int	min;
	int	i;

	min = a->value;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}
