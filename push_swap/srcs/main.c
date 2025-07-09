/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:31:42 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/09 17:17:21 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
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

int	ft_handle_arguments(int argc, char **argv, char ***arguments)
{
	if (argc == 2 && argv[1][0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
		return (1);
	}
	else if (argc == 2)
	{
		*arguments = ft_split(argv[1], ' ');
		if (!arguments)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
			return (1);
		}
	}
	else
		*arguments = ++argv;
	return (0);
}

int	ft_check_errors(char **av, int argc)
{
	if (argc == 2 && av[1][0] == ' ' && av[1][1] == '\0')
		return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE), 0);
	if (argc == 2 && ft_isdigit(av[1][0]) && av[1][1] == '\0')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**arguments;

	arguments = NULL;
	if (ft_check_errors(argv, argc) == 1 || argc == 1)
		return (0);
	if (ft_handle_arguments(argc, argv, &arguments) == 1)
		return (1);
	if (!ft_only_int_check(arguments))
	{
		ft_free_arguments(arguments);
		return (1);
	}
	ft_init_stacks(&stack_a, &stack_b);
	ft_create_stack(arguments, stack_a);
	if (ft_check_all(argc, arguments, stack_a))
	{
		ft_wrong_free(stack_a, stack_b, arguments, argc);
		return (1);
	}
	ft_sort(stack_a, stack_b);
	return (0);
}
