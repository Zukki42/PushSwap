/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:44:15 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/09 20:11:00 by bavirgil         ###   ########.fr       */
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

#endif
