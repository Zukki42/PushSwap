/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:58:23 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/26 10:14:17 by bavirgil         ###   ########.fr       */
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
int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!ft_isdigit(str[i]))
		ft_error();
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			ft_error();
	}
	if (str[i] != '\0')
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
