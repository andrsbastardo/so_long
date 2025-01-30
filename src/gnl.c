/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:39:12 by abastard          #+#    #+#             */
/*   Updated: 2025/01/21 17:39:22 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s)
{
	char	*str;
	char	*dest;
	int		i;

	i = 0;
	str = (char *)s;
	dest = (char *)malloc(ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_read(int fd, char *text)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(text, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			if (text)
				free(text);
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		text = ft_strjoin(text, buff);
	}
	free(buff);
	return (text);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftovers;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftovers = ft_read(fd, leftovers);
	if (!leftovers)
		return (NULL);
	line = ft_get_line(leftovers);
	leftovers = ft_leftovers(leftovers);
	return (line);
}