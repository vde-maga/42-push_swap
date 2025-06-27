/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:52:55 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/27 16:56:09 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					rank;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack
{
	t_stack_node		*top;
	t_stack_node		*bottom;
	int					size;
}						t_stack;

/*
 * ================
 * ===== Misc =====
 * ================
 */

// Ranking
void					ft_assign_ranks(t_stack *stack);
static void				ft_fill_array(int *arr, t_stack *stack);
static void				ft_bubble_sort_array(int *arr, int size);
static void				ft_assign_node_ranks(t_stack *stack, int *arr);

/*
 * =================
 * ===== Utils =====
 * =================
 */

// Datatypes Utils
static int				ft_isdigit(int c);
int						ft_str_just_number(const char *str);
void					ft_parse_args(char **args, t_stack *stack_a,
							int should_free);
long					ft_atol(const char *str);

// Errors
void					ft_exit_error(void);
void					ft_free_stack(t_stack *stack);
void					ft_free_split(char **split);

// Split
static int				ft_total_strings(char const *s, char c);
static int				ft_sep_len(char const *s, char c);
static char				*ft_word(char const *s, char c);
static void				*ft_free_memory(char **strings, int i);
char					**ft_split(char const *s, char c);

// Stack Utils
void					ft_stack_init(t_stack *stack);
void					ft_parse_args(char **args, t_stack *stack_a,
							int should_free);
int						ft_has_duplicate(t_stack *stack_a, int value);
void					ft_free_resources(t_stack *stack_a, t_stack *stack_b,
							char **args, int should_free);

/*
 * ================
 * ===== Sort =====
 * ================
 */

// Sort Utils
int						ft_is_sorted(t_stack *stack);

#endif
