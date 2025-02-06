/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:54:58 by abastard          #+#    #+#             */
/*   Updated: 2025/02/06 06:56:31 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_program(t_graphics *g)
{
	mlx_destroy_window(g->p, g->w);
	system("leaks -q so_long");
	exit(EXIT_SUCCESS);
	return (0);
}

void	check_exit(t_graphics *g)
{
	int	p_x;
	int	p_y;
	int	exit_x;
	int	exit_y;

	p_x = g->inf->player.x;
	p_y = g->inf->player.y;
	exit_x = g->inf->exit.x;
	exit_y = g->inf->exit.y;
	if (g->inf->obj == 0)
		mlx_put_image_to_window(g->p, g->w,
			g->s->exit_op, exit_y * PX, exit_x * PX);
	if (g->inf->clean_map[p_x][p_y] == 'E' &&
		g->inf->obj == 0)
		close_program(g);
	return ;
}

int	key_hook(int key, t_graphics *g)
{
	if (key == ESC || key == KEY_Q)
		close_program(g);
	else if (key == KEY_A || key == KEY_LEFT)
		move_character_a(g);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_character_d(g);
	else if (key == KEY_S || key == KEY_DOWN)
		move_character_s(g);
	else if (key == KEY_W || key == KEY_UP)
		move_character_w(g);
	return (0);
}