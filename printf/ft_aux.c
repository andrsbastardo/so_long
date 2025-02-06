/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:46:31 by abastard          #+#    #+#             */
/*   Updated: 2024/06/11 11:38:02 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_pf(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero_pf(void *s, size_t n)
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

void	*ft_calloc_pf(size_t nmemb, size_t size)
{
	int	*ptr;

	if (nmemb >= SIZE_MAX || size >= SIZE_MAX || (nmemb * size) > SIZE_MAX)
		return (NULL);
	ptr = (int *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero_pf(ptr, nmemb * size);
	return (ptr);
}

static size_t	ft_loops(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen_pf(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_changer_pf(unsigned long long n, char *base)
{
	char	*str;
	int		loop;
	int		base_len;

	loop = ft_loops(n, base);
	base_len = ft_strlen_pf(base);
	str = ft_calloc_pf((loop + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (loop)
	{
		loop -= 1;
		str[loop] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

/* 
ft_address usa el mismo 
procedimiento que para pasar un numero de decimal a binario.
Transformación de n = 100 a decimal
base 01
len 2
n = 100
100 / 2 = 50
50 / 2 = 25
25 / 2 = 12
12 / 2 = 6
6 /2 = 3
3 = 2 = 1
loops = 6 + 1

100 / 2 = 50 resto 0 
base[0] = 0
50 / 2 = 25 resto 0
base[0] = 0
25 / 2 = 12 resto 1
base [1] = 0
12 / 2 = 6 resto 0
base[0] = 0
6 / 2 = 3 resto 0
base[0] = 0
3 / 2 = 1 resto 1
base[1] = 1
1 / 2 = 1
base[1] = 1

Escribimos del final al principio. -> 1100100
Resultado 1100100
Esperado 1100100
*/

/*
Transformación de 16 a decimal(0123456789)
base DECIMAL --> len 10
loop = 1
siempre que n >= 16
16/10=1
loop = 2

16/10 = 1 resto 6
base[6] = 6
1/10 = 1 resto 0
base[1] = 1

Resultado = 16
Esperado = 16
 */