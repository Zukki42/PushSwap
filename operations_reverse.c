/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:57:52 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/22 15:00:12 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** reverse rotate A: last node becomes first. smooth slide. :D
** prints "rra\n".
*/
void	rra(t_stack **a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

/*
** reverse rotate B: same move for stack B. comfy shuffle. :)
** prints "rrb\n".
*/
void	rrb(t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

/*
** double reverse rotate: run rra then rrb, then announce "rrr\n".
** (note: this will print three lines total: rra, rrb, and rrr) D:
*/
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
