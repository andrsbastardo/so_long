/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:19:35 by abastard          #+#    #+#             */
/*   Updated: 2025/01/22 07:14:00 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"



int parse_map(char *str, t_parsemap **mapinf)
{
    printf("open str\n");
    (*mapinf)->fd = open(str,O_RDONLY);
    printf("fd = %d\n",(*mapinf)->fd);
    if ((*mapinf)->fd == -1)
        return(0);
    if(!file_to_map(mapinf))
        return(0);
    
}