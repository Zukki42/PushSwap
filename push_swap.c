/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:56:12 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/22 14:50:43 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** scan stack A for duplicate values. if we spot twins → big nope, error! D:
*/
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

/*
** take one argv string (supports "1 2 3" style), split by spaces,
** atoi each token, and append nodes to stack A. welcome aboard! :D
*/
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

/*
** build stack A from all command-line args (argv[1..n]).
** handles mixed styles like: ./push_swap 3 2 1  and  "./push_swap" "3 2 1"
** also checks for duplicates at the end. safety first! :)
*/
static t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		add_numbers_to_stack(argv[i], &a);
		i++;
	}
	check_duplicates(a);
	return (a);
}

/*
** entry point: parse, early-exit if sorted, then pick a plan:
** tiny stacks → sort_small; bigger adventures → K-sort. good luck.
*/
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (stack_size(a) <= 4)
		sort_small(&a, &b);
	else
	{
		sort_k(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
