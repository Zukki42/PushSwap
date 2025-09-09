/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:56:12 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/09 20:12:16 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicates(t_stack *a)
{
	t_stack	*cur;
	t_stack	*tmp;

	cur = a;
	while (cur)
	{
		tmp = cur->next;
		while (tmp)
		{
			if (cur->value == tmp->value)
				ft_error();
			tmp = tmp->next;
		}
		cur = cur->next;
	}
}

static void	add_numbers_to_stack(char *arg, t_stack **a)
{
	char	**nums;
	int		i;
	int		value;

	nums = ft_split(arg, ' ');
	if (!nums)
		ft_error();
	i = 0;
	while (nums[i])
	{
		value = ft_atoi(nums[i]);
		stack_add_back(a, stack_new(value));
		i++;
	}
	i = 0;
	while (nums[i])
		free(nums[i++]);
	free(nums);
}

static t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
}
