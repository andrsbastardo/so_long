/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:19:35 by abastard          #+#    #+#             */
/*   Updated: 2025/01/28 17:01:12 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	exit_obj_check(t_parsemap **mapinf)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*mapinf)->w_y)
	{
		y = 0;
		while (y < (*mapinf)->w_x)
		{
			if ((*mapinf)->map[x][y] == 'P')
				(*mapinf)->player_num++;
			if ((*mapinf)->map[x][y] == 'C')
				(*mapinf)->obj++;
			if ((*mapinf)->map[x][y] == 'E')
				(*mapinf)->exit_num++;
			y++;
		}
		x++;
	}
	if ((*mapinf)->player_num != 1 || (*mapinf)->exit_num != 1
		|| (*mapinf)->obj == 0)
		return (0);
	return (1);
}


int	borders_check(t_parsemap **mapinf)
{
	int	total;
	int	len;
	int	x;
	int	y;

	x = 0;
	y = 0;
	total = (*mapinf)->w_y;
	len = (*mapinf)->w_x;
	while (y < len)
	{
		if ((*mapinf)->map[0][y] != '1' ||
			(*mapinf)->map[total - 1][y] != '1')
			return (0);
		y++;
	}
	while (x < (total - 1))
	{
		if ((*mapinf)->map[x][0] != '1' ||
			(*mapinf)->map[x][len - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

int count_height(t_parsemap **mapinf)
{
    int i;

    i = 0;
    while ((*mapinf)->clean_map[i])
    {
        printf("%s\n", (*mapinf)->clean_map[i]);
        i++;
    }
    (*mapinf)->w_y = i;
    return(i);
}

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
    count_height(mapinf);
    if(!borders_check(mapinf))
    {
        printf("Error border\n");
        return(0);
    }
    if(!exit_obj_check(mapinf))
    {
        printf("Error obj\n");
        return(0);
    }
    if(!validate_map(mapinf))
    {
        printf("Not valid map\n");
        return(0);
    } 
    return(1);
}
