/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:44:15 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/11 19:15:01 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // malloc, free, exit
# include <unistd.h> // write

// STRUCT
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// UTILS.C FUNCTIONS
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
void				ft_error(void);
int					is_sorted(t_stack *a);

// SPLIT.C FUNCTIONS
char				**ft_split(char const *s, char c);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);

// STACK_UTILS.C FUNCTIONS
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **a, t_stack *new);
int					stack_size(t_stack *a);
void				free_stack(t_stack **a);

// OPERATIONS_SWAP.C FUNCTIONS
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

// OPERATIONS_PUSH.C FUNCTIONS
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

// OPERATIONS_ROTATE.C FUNCTIONS
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

// OPERATIONS_REVERSE.C FUNCTIONS
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// SORT_SMALL.C FUNCTIONS
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_small(t_stack **a, t_stack **b);

// INDEXING.C FUNCTIONS
void				assign_index(t_stack *a);
int					find_max_index(t_stack *stack);
int					position_of_index(t_stack *stack, int target);

#endif
