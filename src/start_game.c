/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 07:54:13 by abastard          #+#    #+#             */
/*   Updated: 2025/02/06 06:55:25 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(t_parsemap *mapinf)
{
	t_sprites	*s;
	t_graphics	*g;

	g = malloc(sizeof(t_graphics));
	s = malloc(sizeof(t_sprites));
	if (!s || !g)
		return(0);
	g->inf = mapinf;
	g->s = s;
	g->p = mlx_init();
	if (!g->p)
		return(0);
	g->w = mlx_new_window(g->p, (mapinf->w_x * PX),
			(mapinf->w_y * PX), "so_long");
	if (!g->w)
		return(0);
	init_image(g, s);
	mlx_key_hook(g->w, &key_hook, g);
	mlx_hook(g->w, 17, 0, close_program, g);
	mlx_loop(g->p);
	return (1);
}
