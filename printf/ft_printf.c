/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:13:40 by abastard          #+#    #+#             */
/*   Updated: 2024/06/14 12:42:40 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	continuation(char *str, size_t *counter, size_t i, size_t *flag)
{
	ft_character_pf(str[i - 1], counter);
	if ((str[i] >= 32 && str[i] <= 47)
		|| (str[i] >= 58 && str[i] <= 126))
	{
		(*flag)++;
		ft_character_pf(str[i], counter);
	}
}

int	ft_format(va_list va, char *str, size_t *counter, size_t i)
{
	size_t	flag;

	flag = 0;
	if (str[i] == 'c')
		ft_character_pf(va_arg(va, int), counter);
	else if (str[i] == 's')
		ft_string_pf(va_arg(va, char *), counter);
	else if (str[i] == 'p')
		ft_pointer_pf(va_arg(va, void *), counter);
	else if (str[i] == 'i' || str[i] == 'd')
		ft_putnbr_pf(va_arg(va, int), counter);
	else if (str[i] == 'u')
		ft_hex_pf(va_arg(va, unsigned int), counter, DECIMAL);
	else if (str[i] == 'x')
		ft_hex_pf(va_arg(va, unsigned int), counter, HEX_LOW_BASE);
	else if (str[i] == 'X')
		ft_hex_pf(va_arg(va, unsigned int), counter, HEX_UP_BASE);
	else if (str[i] == '%')
		ft_character_pf(str[i], counter);
	else
		continuation((char *)str, counter, i, &flag);
	return (flag);
}

void	conditional(char *str, size_t *counter, size_t i, size_t *flag)
{
	if (str[i] != '%')
		ft_character_pf(str[i], counter);
	else if (str[i] == '%' && str[i + 1] == '\0' && *flag >= 1)
		ft_character_pf(str[i], counter);
}

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	counter;
	size_t	i;
	size_t	flag;

	if (!str)
		return (0);
	counter = 0;
	i = 0;
	flag = 0;
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			flag = ft_format(va, (char *)str, &counter, i);
		}
		else
			conditional((char *)str, &counter, i, &flag);
		i++;
	}
	va_end(va);
	return (counter);
}
