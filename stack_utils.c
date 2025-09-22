/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:57:00 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/22 14:02:24 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Make a fresh stack node with given value. if malloc says "nope",
	we error out. D:
*/
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->value = value;
	new->next = NULL;
	return (new);
}

/*
** Append a node to the end of stack 'a'. handles empty list too (nice!). :D
*/
void	stack_add_back(t_stack **a, t_stack *new)
{
	t_stack	*last;

	if (!a || !new)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = new;
}

/*
** Count how many nodes live in this stack. numbers go brrr. :>
*/
int	stack_size(t_stack *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

/*
** Free the whole stack safely and set the head to NULL. goodbye,
	little nodes. D:
*/
void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}
