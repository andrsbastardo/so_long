/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:41 by abastard          #+#    #+#             */
/*   Updated: 2025/01/25 15:57:44 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int ft_strlen_mod(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0' && str[count] != '\n')
		count++;
	return (count);
}

char *ft_strjoin_mod(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) + (ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strncmpend(char *s1, char *s2, int n)
{
	int	len;

	len = ft_strlen_mod(s1) - 1;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		--n;
		if (s1[len] != s2[n])
			return (0);
		len--;
	}
	return (1);
}