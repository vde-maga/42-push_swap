/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:49:07 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/18 14:39:35 by vde-maga         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**args;
	int	should_free;
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
}
