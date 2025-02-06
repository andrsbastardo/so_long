/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:35:27 by abastard          #+#    #+#             */
/*   Updated: 2024/06/14 12:52:08 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// desccripción básica de la fiunción
void	ft_hex_pf(unsigned int num, size_t *counter, char *base)
{
	char	*str;

	str = ft_changer_pf(num, base);
	ft_string_pf(str, counter);
	free(str);
}
