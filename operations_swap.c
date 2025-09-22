/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:57:21 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/22 14:47:25 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** swap the first two elements of stack A. quick lil’ flip! :D
** prints "sa\n".
*/
void	sa(t_stack **a)
{
	t_stack	*tmp;
	int		val;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	val = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = val;
	write(1, "sa\n", 3);
}

/*
** swap the first two elements of stack B. same party, other stack. :)
** prints "sb\n".
*/
void	sb(t_stack **b)
{
	t_stack	*tmp;
	int		val;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	val = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = val;
	write(1, "sb\n", 3);
}

/*
** double-swap: do sa and sb together (if each has ≥2). efficiency boost! 🚀
** prints "ss\n".
*/
void	ss(t_stack **a, t_stack **b)
{
	int	val;

	if (a && *a && (*a)->next)
	{
		val = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = val;
	}
	if (b && *b && (*b)->next)
	{
		val = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = val;
	}
	write(1, "ss\n", 3);
}
