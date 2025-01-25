/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:01:04 by abastard          #+#    #+#             */
/*   Updated: 2025/01/25 16:06:22 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	*ptr;

	if (nmemb >= SIZE_MAX || size >= SIZE_MAX || (nmemb * size) > SIZE_MAX)
		return (NULL);
	ptr = (int *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	char	*final;

	if (!n)
		return (0);
	final = (char *)src;
	while ((n > 1) && (*final))
	{
		*dest++ = *final++;
		n--;
	}
	if (*dest)
		*dest = '\0';
	return (0);
}
