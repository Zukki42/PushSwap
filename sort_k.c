/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:58:12 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/22 15:15:08 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** choose the chunk/window size based on n. tiny? still at least 1. :D
*/
static int	calc_delta(int n)
{
	int	d;

	d = n / 20 + 7;
	if (d < 1)
		d = 1;
	return (d);
}

/*
** phase 1: slide through A and push to B when index fits the window.
** small ones get a bonus rb so they sink a bit in B. strategy! >:D
*/
static void	distribute_to_b(t_stack **a, t_stack **b, int delta)
{
	int	threshold;

	threshold = 0;
	while (*a)
	{
		if ((*a)->index <= threshold + delta)
		{
			pb(a, b);
			if ((*b)->index <= threshold)
				rb(b);
			threshold++;
		}
		else
			ra(a);
	}
}

/*
** helper: rotate B in the shorter direction to bring current max on top.
** fewer spins = happier wrists.
*/
static void	bring_max_to_top(t_stack **b, int max_index)
{
	int	size;
	int	pos;

	if (!b || !*b)
		return ;
	size = stack_size(*b);
	pos = position_of_index(*b, max_index);
	while (*b && (*b)->index != max_index)
	{
		if (pos <= size / 2)
			rb(b);
		else
			rrb(b);
		pos = position_of_index(*b, max_index);
	}
}

/*
** phase 2: keep grabbing the biggest from B and pa it back to A.
** repeat until B is empty and A is shiny-sorted. ✨
*/
static void	collect_back_to_a(t_stack **a, t_stack **b)
{
	int	max;

	while (*b)
	{
		max = find_max_index(*b);
		bring_max_to_top(b, max);
		pa(a, b);
	}
}

/*
** public entry: K-sort! index everything, distribute with a delta window,
** then collect back in descending index order. easy, breezy, sorted. :)
*/
void	sort_k(t_stack **a, t_stack **b)
{
	int	n;
	int	delta;

	if (!a || !*a)
		return ;
	assign_index(*a);
	n = stack_size(*a);
	delta = calc_delta(n);
	distribute_to_b(a, b, delta);
	collect_back_to_a(a, b);
}
