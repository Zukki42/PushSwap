/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:02:07 by bavirgil          #+#    #+#             */
/*   Updated: 2025/09/22 14:04:25 by bavirgil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** count how many words are in 's' separated by delimiter 'c'.
** returns the number of chunks you'll need. neat! :D
*/
static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

/*
** fill the pre-allocated array 'arr' with freshly malloc'd strings,
** each being one word split by 'c'. frees partial on failure (phew). :)
*/
static char	**fill_split(char **arr, char const *s, char c, int wc)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (*s && i < wc)
	{
		while (*s == c)
			s++;
		while (s[len] && s[len] != c)
			len++;
		arr[i] = malloc(len + 1);
		if (!arr[i])
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		ft_strlcpy(arr[i++], s, len + 1);
		s += len;
		len = 0;
	}
	arr[i] = NULL;
	return (arr);
}

/*
** split 's' by delimiter 'c' into a NULL-terminated array of strings.
** returns the new array or NULL on allocation sadness. D:
*/
char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		wc;

	if (!s)
		return (NULL);
	wc = count_words(s, c);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	arr = fill_split(arr, s, c, wc);
	return (arr);
}

/*
** copy up to dstsize-1 chars from src into dst, always NUL-terminating.
** returns the total length of src (so you can detect truncation). :>
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
** classic strlen — count bytes in 's' before the terminating '\0'.
** yes, we walk the whole thing. cardio time. 🏃‍♂️
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
