/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:23:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/11 15:08:31 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_exit_error(void)
{
	write(2, "Error\n", 6);
}

void	ft_free(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	free(stack);
}

void	ft_free_arguments(char **arguments)
{
	int	i;

	if (!arguments)
		return ;
	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

void	ft_wrong_free(t_stack **stack_a, t_stack **stack_b, char **av, int ac)
{
	if (ac == 2)
		ft_free_arguments(av);
	if (stack_a)
		ft_free(stack_a);
	if (stack_b)
		ft_free(stack_b);
}
