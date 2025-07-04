/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:52:55 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/04 18:06:21 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			value;
	int				index;
	struct s_stack	*next;
}					t_stack;
/*
 * =============================================================================
 * ================================ Error ======================================
 * =============================================================================
 */
void				ft_exit_error(void);
void				ft_free(t_stack **stack);
void				ft_free_arguments(char **argv);
void				ft_wrong_free(t_stack **stack_a, t_stack **stack_b,
						char **av, int ac);

/*
 * =============================================================================
 * ================================ Operations =================================
 * =============================================================================
 */
//				ft_swap
void				ft_swap(char c, t_stack **stack_a, t_stack **stack_b);
//				ft_rotate
void				ft_rotate(char c, t_stack **stack_a, t_stack **stack_b);
void				ft_reverse_rotate(char c, t_stack **stack_a,
						t_stack **stack_b);
//				ft_push
void				ft_push(char c, t_stack **stack_to, t_stack **stack_from);

/*
 * =============================================================================
 * =================================== Sort ====================================
 * =============================================================================
 */
// ft_sort_small
void				ft_sort_small(t_stack **stack_a, t_stack **stack_b,
						int size);
void				ft_radix(t_stack **stack_a, t_stack **stack_b);

/*
 * =============================================================================
 * =================================== Stack ===================================
 * =============================================================================
 */
//				init
void				ft_init_stacks(t_stack ***a, t_stack ***b);
void				ft_create_stack(char **argv, t_stack **stack);
void				ft_put_first_index(t_stack **stack);

//				stack_utils
int					ft_get_stack_size(t_stack **stack);
t_stack				*ft_get_last(t_stack **stack);
t_stack				*ft_get_second_last(t_stack **stack);
int					ft_get_min(t_stack **stack);

//				radix_stack_utils
int					ft_get_bits(t_stack **stack);
//				ft_sort_small_utils
int					ft_get_pos_min(t_stack *a);

/*
 * =============================================================================
 * =================================== Utils ===================================
 * =============================================================================
 */
//				checkers
int					ft_only_int_check(char **argv);
int					ft_is_sorted(t_stack **stack);
int					ft_check_all(int argc, char **argv, t_stack **stack);
int					ft_is_integer(char **argv);

//				ft_split
char				**ft_split(char const *s, char c);

//				libft
int					ft_isdigit(int c);
long				ft_atol(const char *str);

#endif
