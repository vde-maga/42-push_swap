/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:21:37 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/04 18:04:39 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_init_stacks(t_stack ***a, t_stack ***b)
{
	*a = (t_stack **)malloc(sizeof(t_stack *));
	*b = (t_stack **)malloc(sizeof(t_stack *));
	**a = NULL;
	**b = NULL;
}

void	ft_create_stack(char **argv, t_stack **stack)
{
	int		i;
	t_stack	*list;

	i = 0;
	*stack = malloc(sizeof(t_stack));
	if (!stack)
		return ;
	(*stack)->value = ft_atol(argv[i++]);
	(*stack)->index = -1;
	(*stack)->next = NULL;
	list = *stack;
	while (argv[i])
	{
		list->next = malloc(sizeof(t_stack));
		if (!list->next)
			return (ft_free(stack));
		list = list->next;
		list->value = ft_atol(argv[i]);
		list->index = -1;
		list->next = NULL;
		i++;
	}
	return ;
}

void	ft_put_all_index(t_stack **stack, int index)
{
	long	min;
	t_stack	*temp;

	temp = *stack;
	while (temp->next && temp->index != -1)
		temp = temp->next;
	if (temp->index != -1)
		return ;
	min = temp->value;
	while (temp)
	{
		if (min > temp->value && temp->index == -1)
			min = temp->value;
		temp = temp->next;
	}
	temp = *stack;
	while (temp->value != min)
		temp = temp->next;
	temp->index = index;
	ft_put_all_index(stack, ++index);
}

void	ft_put_first_index(t_stack **stack)
{
	t_stack	*temp;
	long	min;

	temp = *stack;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	temp = *stack;
	while (min != temp->value)
		temp = temp->next;
	temp->index = 0;
	ft_put_all_index(stack, 1);
}
