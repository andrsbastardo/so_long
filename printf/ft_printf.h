/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:18 by abastard          #+#    #+#             */
/*   Updated: 2024/06/14 12:47:55 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

# define HEX_UP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"
# define DECIMAL "0123456789"

int		ft_printf(char const *str, ...);

/* format functions */
void	ft_character_pf(char c, size_t *counter);
void	ft_string_pf(char *str, size_t *counter);
void	ft_putnbr_pf(int num, size_t *counter);
void	ft_putint_pf(unsigned int num, size_t *counter);
void	ft_hex_pf(unsigned int num, size_t *counter, char *base);
void	ft_pointer_pf(void *ptr, size_t *counter);

/* auxiliary functions */
char	*ft_changer_pf(unsigned long long n, char *base);

#endif