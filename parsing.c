/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 03:55:05 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/11 03:55:56 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Free a NULL-terminated string array from ft_split */
static void	free_split(char **arr)
{
	int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/* Optional [+/-] then at least one digit; all chars must be digits */
static int	is_int_token(const char *s)
{
	int i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Check 32-bit signed range without allocating */
static int	fits_int_range(const char *s)
{
	long	sign;
	long	val;
	int		i;

	sign = 1;
	val = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		sign = (s[i++] == '-') ? -1 : 1;
	while (s[i])
	{
		val = val * 10 + (s[i] - '0');
		if (sign == 1 && val > 2147483647L)
			return (0);
		if (sign == -1 && -val < -2147483648L)
			return (0);
		i++;
	}
	return (1);
}

/* Return 1 if duplicates exist in A, else 0 */
int	has_duplicates(t_stack *a)
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
				return (1);
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

/* Split one argv, validate tokens, append to A; free everything before error */
void	add_numbers_to_stack(char *arg, t_stack **a)
{
	char	**nums;
	int		i;
	int		value;

	nums = ft_split(arg, ' ');
	if (!nums)
	{
		free_stack(a);
		ft_error();
	}
	i = 0;
	while (nums[i])
	{
		if (!is_int_token(nums[i]) || !fits_int_range(nums[i]))
		{
			free_split(nums);
			free_stack(a);
			ft_error();
		}
		value = ft_atoi(nums[i]);
		stack_add_back(a, stack_new(value));
		i++;
	}
	free_split(nums);
}
