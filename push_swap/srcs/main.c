/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:31:42 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/10 18:59:55 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_end(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_get_stack_size(stack_a) <= 5)
	{
		ft_sort_small(stack_a, stack_b, ft_get_stack_size(stack_a));
		ft_free(stack_a);
		ft_free(stack_b);
		return ;
	}
	ft_radix(stack_a, stack_b);
	ft_free(stack_a);
	ft_free(stack_b);
}

int	ft_check_errors(char **av, int argc)
{
	if (argc == 2 && av[1][0] == ' ' && av[1][1] == '\0')
	{
		ft_exit_error();
		return (0);
	}
	if (argc == 2 && ft_isdigit(av[1][0]) && av[1][1] == '\0')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**arguments;

	arguments = NULL;
	if (!ft_check_errors(argv, argc) || argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
	{
		ft_exit_error();
		return (1);
	}
	else if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
		arguments = ++argv;
	if (!ft_only_int_check(arguments))
	{
		ft_free_arguments(arguments);
		return (1);
	}
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_create_stack(arguments, stack_a);
	if (ft_check_all(argc, arguments, stack_a))
		return (ft_wrong_free(stack_a, stack_b, arguments, argc), 1);
	return (ft_end(stack_a, stack_b), 0);
}
