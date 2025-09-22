/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:57:47 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/22 15:03:14 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** give every node a rank (index) based on its value:
** smallest -> 0, next -> 1, ... largest -> n-1. tidy and normalized. :D
*/
void	assign_index(t_stack *a)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		index;

	cur = a;
	while (cur)
	{
		index = 0;
		cmp = a;
		while (cmp)
		{
			if (cmp->value < cur->value)
				index++;
			cmp = cmp->next;
		}
		cur->index = index;
		cur = cur->next;
	}
}

/*
** scan the stack and return the biggest index you can find.
** returns -1 if the stack is empty (sad). D:
*/
int	find_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

/*
** find where a given index lives in the stack (0-based position).
** returns -1 if it’s not there (rude!).
*/
int	position_of_index(t_stack *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
