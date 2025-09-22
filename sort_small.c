/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:58:02 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/22 14:06:42 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** tiny stack? easy win. if two are out of order, just bonk 'sa' :D
*/
void	sort_two(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

/*
** the spicy trio puzzle — handle the 5 unsorted cases with sa/ra/rra.
** always finishes in a couple moves. chef’s kiss. 😌
*/
void	sort_three(t_stack **a)
{
	int	a_val;
	int	b_val;
	int	c_val;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	a_val = (*a)->value;
	b_val = (*a)->next->value;
	c_val = (*a)->next->next->value;
	if (a_val > b_val && b_val < c_val && a_val < c_val)
		sa(a);
	else if (a_val > b_val && b_val > c_val)
	{
		sa(a);
		rra(a);
	}
	else if (a_val > b_val && b_val < c_val && a_val > c_val)
		ra(a);
	else if (a_val < b_val && b_val > c_val && a_val < c_val)
	{
		sa(a);
		ra(a);
	}
	else if (a_val < b_val && b_val > c_val && a_val > c_val)
		rra(a);
}

/*
** find the node with the smallest value (our VIP guest to push first). ✨
*/
static t_stack	*find_min(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}

/*
** for four: rotate the smallest to the top, push to B, sort the remaining 3,
** then pull it back. neat lil’ routine. :D
*/
void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min;

	if (!a || !*a || stack_size(*a) != 4)
		return ;
	min = find_min(*a);
	while (*a != min)
	{
		if (stack_size(*a) / 2 > 1)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

/*
** wrapper for baby stacks: dispatch to the right tiny strategy. go go go!
*/
void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
}
