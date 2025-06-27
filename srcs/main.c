/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:49:07 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/27 16:53:25 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**ft_get_args(int argc, char **argv, int *should_free)
{
	char	**args;

	*should_free = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*should_free = 1;
	}
	else
		args = &argv[1];
	return (args);
}

static void	ft_sort_stack(t_stack *a, t_stack *b)
{
	if (!ft_is_sorted(a))
	{
		if (a->size <= 5)
			ft_sort_small_stack(a, b);
		else
			ft_sort_radix(a, b);
	}
}

int	main(int argc, char **argv)
{
	char	**args;
	int		should_free;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (1);
	args = ft_get_args(argc, argv, &should_free);
	if (!args)
		ft_exit_error();
	ft_stack_init(&stack_a);
	ft_stack_init(&stack_b);
	ft_parse_args(args, &stack_a, should_free);
	ft_assign_ranks(&stack_a);
	ft_sort_stack(&stack_a, &stack_b);
}
