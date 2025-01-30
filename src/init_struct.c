/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:24:50 by abastard          #+#    #+#             */
/*   Updated: 2025/01/23 18:06:45 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_parsemap	*init_struct(void)
{
	t_parsemap	*mapinf;

	mapinf = malloc(sizeof(t_parsemap));
	mapinf->w_x = -1;
	mapinf->w_y = -1;
	mapinf->fd = 0;
	mapinf->map = NULL;
	mapinf->clean_map = NULL;
	mapinf->obj = 0;
	mapinf->exit_num = 0;
	mapinf->player_num = 0;
	mapinf->exit_check = 0;
	mapinf->obj_check = 0;
	mapinf->player.mov = 0;
	return (mapinf);
}