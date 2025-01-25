/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:19:35 by abastard          #+#    #+#             */
/*   Updated: 2025/01/25 16:18:55 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int file_to_map(t_parsemap **mapinf)
{
    char *str;
    char *aux;
    
    aux = malloc(sizeof(char));
    str = get_next_line((*mapinf)->fd);
    (*mapinf)->w_x = ft_strlen_mod(str);
    while(str)
    {
        aux = ft_strjoin_mod(aux,str);
        if (ft_strlen_mod(str) != (*mapinf)->w_x)
        {
            printf("NO ES UN RECTANGULO");
            return(0);
        }
        str = get_next_line((*mapinf)->fd);
    }
    (*mapinf)->clean_map = ft_split(aux,'\n');
    (*mapinf)->map = (*mapinf)->clean_map;
    return(1);
}

int parse_map(char *str, t_parsemap **mapinf)
{
    (*mapinf)->fd = open(str,O_RDONLY);
    if ((*mapinf)->fd == -1)
        return(0);
    if(!file_to_map(mapinf))
        return(0);
    return(1);
}