/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:20:09 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/07 23:42:04 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find where the smallest lil’ guy is hiding in A (0-based).
** TL;DR: walk the stack, remember the tiniest and its seat number. */
static int	pos_of_min(t_stack *a)
{
	t_stack	*p;
	int		pos;
	int		i;
	int		minv;

	pos = 0;
	i = 0;
	minv = a->value;
	p = a;
	while (p)
	{
		if (p->value < minv)
		{
			minv = p->value;
			pos = i;
		}
		p = p->next;
		i++;
	}
	return (pos);
}

/* Bring the current minimum to the top of A using the shorter path.
** If it’s closer via ra, we ra; if not, we rra. No cardio wasted. */
static void	rotate_min_to_top(t_stack **a)
{
	int	size;
	int	pos;

	size = stack_size(*a);
	pos = pos_of_min(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
}

/* Hard-coded 5-sort:
** 1) yeet two minima to B
** 2) sort the remaining trio on A
** 3) flip B if needed so the 2nd-smallest is on top
** 4) pa, pa — tada, sorted. */
void	sort_five(t_stack **a, t_stack **b)
{
	rotate_min_to_top(a);
	pb(a, b);
	rotate_min_to_top(a);
	pb(a, b);
	sort_three(a);
	if (*b && (*b)->next && (*b)->value < (*b)->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}
