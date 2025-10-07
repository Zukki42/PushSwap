/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:58:23 by bavirgil          #+#    #+#             */
/*   Updated: 2025/10/08 00:19:44 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if 'c' is an ASCII digit ('0'..'9'). numbers good? :D
** Returns 1 if yes, 0 if nope.
*/
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
/*
** Something went wrong — print "Error\n" to stderr and bail. D:
** Use when parsing/logic hits invalid territory.
*/

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/*
** Super strict ASCII-to-int (no funny business >:|).
** - Skips leading whitespace
** - Optional +/-
** - Requires at least one digit (no lonely '+' or '-'!)
** - Checks 32-bit overflow/underflow
** - Fails if trailing junk remains
** Returns the parsed int if everything is squeaky clean. :)
*/
int	ft_atoi(const char *a)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((a[i] >= 9 && a[i] <= 13) || a[i] == ' ')
		i++;
	if (a[i] == '-' || a[i] == '+')
		if (a[i++] == '-')
			sign = -1;
	if (!ft_isdigit(a[i]))
		ft_error();
	while (ft_isdigit(a[i]))
	{
		result = result * 10 + (a[i++] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			ft_error();
	}
	if (a[i] != '\0')
		ft_error();
	return ((int)(result * sign));
}

/*
** Is stack A sorted in ascending order? we love to see it :D
** Empty or single-node stacks count as sorted (free wins).
** Returns 1 if sorted, 0 otherwise.
*/
int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

/*
1. takes care of the minus and pluses and fixes the leak so you take care of special cases
*/
int	is_valid(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i]) // sign only -> invalid
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
