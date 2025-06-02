/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:06:19 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/02 18:14:06 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ft_substr(char *str, int start, int length)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = ft_strlen(str);

	if (!str)
		return (0);
	if (length > size)
		dest = malloc(sizeof(char) * (size + 1));
	else
		dest = malloc(sizeof(char) * (length + 1));
	if (!dest)
		return (0);
	while (start < size && i < length && str[start])
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
