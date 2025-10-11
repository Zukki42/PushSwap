/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:56:12 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/11 03:57:42 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *parse_args(int argc, char **argv)
{
    t_stack *a = NULL;
    int i = 1;

    while (i < argc)
        add_numbers_to_stack(argv[i++], &a);
    if (!a)
        exit(0);
    if (has_duplicates(a))
    {
        free_stack(&a);
        ft_error();
    }
    return a;
}

static void dispatch_sort(t_stack **a, t_stack **b)
{
    int size;

    if (is_sorted(*a))
        return;
    size = stack_size(*a);
    if (size <= 4)
        sort_small(a, b);
    else if (size == 5)
        sort_five(a, b);
    else
    {
        assign_index(*a);
        sort_k(a, b);
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return 0;
    a = parse_args(argc, argv);
    b = NULL;
    dispatch_sort(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return 0;
}
