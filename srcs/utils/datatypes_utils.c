/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:42:50 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/18 14:54:11 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static long	ft_parse_number(const char *str, int *i, int signal)
{
	long	result;

	result = 0;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		if (signal == 1 && result > (LONG_MAX -  (str[*i] - '0')) / 10)
			ft_exit_error();
		if (signal == -1 && -(result) < (LONG_MIN +  (str[*i] - '0')) / 10)
			ft_exit_error();
		result = result * 10 + (str[*i] - '0');
		i++;
	}
	return (result * signal);
}

long	ft_atol(const char *str)
{
	long	result;
	int	signal;
	int	i;

	result = 0;
	signal = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	result = ft_parse_number(str, &i, signal);
}
