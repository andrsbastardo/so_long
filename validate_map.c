/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:33:22 by abastard          #+#    #+#             */
/*   Updated: 2025/01/28 16:59:46 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void water_pour(t_parsemap **mapinf, int x, int y)
{
    if ((*mapinf)->map[x][y] == '1' || (*mapinf)->map[x][y] =='A')
        return;
    if((*mapinf)->map[x][y] == 'C')
        (*mapinf)->obj_check++;
    if((*mapinf)->map[x][y] == 'E')
        (*mapinf)->exit_check++;
    (*mapinf)->map[x][y] = 'A';
    water_pour(mapinf, x, (y + 1));
	water_pour(mapinf, x, (y - 1));
	water_pour(mapinf, (x + 1), y);
	water_pour(mapinf, (x - 1), y);
}

int check_exit_player(t_parsemap **mapinf)
{
    int	x;
	int	y;

	x = 0;
	while ((*mapinf)->map[x])
	{
		y = 0;
		while ((*mapinf)->map[x][y])
		{
			if ((*mapinf)->map[x][y] == 'P')
			{
				(*mapinf)->player.x = x;
				(*mapinf)->player.y = y;
			}
			if ((*mapinf)->map[x][y] == 'E')
			{
				(*mapinf)->exit.x = x;
				(*mapinf)->exit.y = y;
			}
			y++;
		}
		x++;
	}
	return(1);
}


int validate_map(t_parsemap **mapinf)
{
    check_exit_player(mapinf);
    water_pour(mapinf,(*mapinf)->player.x, (*mapinf)->player.y);
    if ((*mapinf)->exit_num != (*mapinf)->exit_check)
    {
        printf("Exit num(%d) != exit_check(%d)\n" ,(*mapinf)->exit_num, (*mapinf)->exit_check);
        return (0);
    }
    if ((*mapinf)->obj != (*mapinf)->obj_check)
    {
        printf("obj(%d) != obj_check(%d)\n" ,(*mapinf)->obj, (*mapinf)->obj_check);
        return (0);
    }
		
    return(1);
}