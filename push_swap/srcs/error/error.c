/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:23:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/10 17:44:03 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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

void	ft_free_arguments(char **argv)
{
	int	i;
	
	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
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
