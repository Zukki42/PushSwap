/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:57:21 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/08 14:57:23 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	int val = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = val;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	int val = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = val;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	if (a && *a && (*a)->next)
	{
		int val = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = val;
	}
	if (b && *b && (*b)->next)
	{
		int val = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = val;
	}
	write(1, "ss\n", 3);
}
