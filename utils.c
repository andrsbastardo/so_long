/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:22:41 by abastard          #+#    #+#             */
/*   Updated: 2025/01/21 17:47:57 by abastard         ###   ########.fr       */
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