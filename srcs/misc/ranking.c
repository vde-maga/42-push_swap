/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:53:56 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/20 16:27:55 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_bubble_sort_array(int *arr, int size)
{
	int	swapped;
	int	i;
	int	j;
	int	temp;

	if (!arr || size < 2)
		return ;
	i = -1;
	while (++i < size - 1)
	{
		swapped = 0;
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
			break ;
	}
}

static void	ft_fill_array(int *arr, t_stack *stack)
{
	t_stack_node	*node;
	int				i;

	node = stack->top;
	i = 0;
	while (node)
	{
		arr[i++] = node->value;
		node = node->next;
	}
}

static void	ft_assign_node_ranks(t_stack *stack, int *arr)
{
	t_stack_node	*node;
	int				i;

	node = stack->top;
	while (node)
	{
		i = 0;
		while (arr[i] != node->value)
			i++;
		node->rank = i;
		node = node->next;
	}
}

void	ft_assign_ranks(t_stack *stack)
{
	int	*arr;

	if (!stack || !stack->top || stack->size == 0)
		return ;
	arr = (int *)malloc(sizeof(int) * stack->size);
	if (!arr)
		ft_exit_error();
	ft_fill_array(arr, stack);
	ft_bubble_sort_array(arr, stack->size);
	ft_assign_node_ranks(stack, arr);
	free(arr);
}
