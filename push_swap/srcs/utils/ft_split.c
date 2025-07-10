/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:06:53 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/08 16:54:33 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static size_t	ft_count_words(char *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			words++;
		while (str[i] != c && str[i])
			i++;
	}
	return (words);
}

static char	*ft_dup(const char *str, size_t start, size_t len)
{
	char	*string;
	size_t	i;

	i = 0;
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	while (i < len)
	{
		string[i] = str[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

static void	ft_free_memory(size_t i, char **strings)
{
	size_t	k;

	k = 0;
	while (i > k)
	{
		free(strings[k]);
		k++;
	}
	free(strings);
}

static char	**ft_while(char c, const char *s, char **strings, size_t start)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_count_words((char *)s, c))
	{
		while (s[j] == c && s[j])
			j++;
		start = j;
		while (s[j] != c && s[j])
			j++;
		strings[i] = ft_dup(s, start, j - start);
		if (!strings[i])
		{
			ft_free_memory(i, strings);
			return (NULL);
		}
		i++;
	}
	strings[i] = NULL;
	return (strings);
}

char	**ft_split(const char *s, char c)
{
	char	**strings;
	size_t	start;
	size_t	words;

	start = 0;
	words = ft_count_words((char *)s, c);
	strings = malloc(sizeof(char *) * (words + 1));
	if (!strings)
		return (NULL);
	strings = ft_while(c, s, strings, start);
	return (strings);
}
/*
#include <stdio.h>
int	main()
{
	char string[] = "hello!";
	char **ret = ft_split(string, ' ');
	for (size_t i = 0; i < 2; i++)
	{
		printf("%s\n", ret[i]);
		free(ret[i]);
	}
	free(ret);
}
*/
