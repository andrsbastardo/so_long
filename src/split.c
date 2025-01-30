/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:59:42 by abastard          #+#    #+#             */
/*   Updated: 2025/01/28 16:15:05 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**free_willy(char **res, size_t i)
{
	while (i--)
	{
		free(res[i]);
	}
	free(res);
	return (NULL);
}

static size_t	string_counter(char const *s, char c)
{
	size_t	string;
	size_t	counter;
	size_t	i;

	i = 0;
	string = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			counter = 0;
		else if (counter == 0)
		{
			string++;
			counter = 1;
		}
		i++;
	}
	return (string);
}

static char	**coupler(char **res, char const *s, char c, size_t string)
{
	size_t	index;
	size_t	counter;

	index = 0;
	while (index < string && *s)
	{
		counter = 0;
		while (*s == c)
			s++;
		while (s[counter] != c && s[counter])
			counter++;
		res[index] = (char *)ft_calloc(sizeof(char), (counter + 1));
		if (!res[index])
			return (free_willy(res, (index)));
		ft_strlcpy(res[index], s, counter + 1);
		index++;
		s += counter;
	}
	return (res);
}


char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	string;

	if (!s || !*s)
		return ((char **)ft_calloc(sizeof(char *), 1));
	string = string_counter(s, c);
	res = ft_calloc(sizeof(char *), (string + 1));
	if (!res)
		return (NULL);
	return (coupler(res, s, c, string));
}