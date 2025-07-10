/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:15:32 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/10 19:01:32 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_only_int_check(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
		{
			if ((j == 0) && (arguments[i][j] == '-' || arguments[i][j] == '+'))
				j++;
			if (!ft_isdigit(arguments[i][j]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_sorted(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	temp = *stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_is_duplicate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next_temp;

	if (!stack || !(*stack))
		return (1);
	temp = *stack;
	while (temp->next)
	{
		next_temp = temp->next;
		while (next_temp)
		{
			if (!next_temp)
				break ;
			if (temp->value == next_temp->value)
			{
				ft_exit_error();
				return (0);
			}
			next_temp = next_temp->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	ft_is_integer(char **argv)
{
	int		i;
	long	number;

	i = 0;
	while (argv[i])
	{
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			ft_exit_error();
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_all(int argc, char **argv, t_stack **stack)
{
	if (!ft_is_integer(argv))
		return (1);
	if (!ft_only_int_check(argv))
		return (1);
	if (!ft_is_duplicate(stack))
		return (1);
	if (ft_is_sorted(stack))
		return (1);
	if (argc == 2)
		ft_free_arguments(argv);
	return (0);
}
