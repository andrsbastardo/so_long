/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:57:35 by abastard          #+#    #+#             */
/*   Updated: 2025/02/10 18:15:56 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_character_d(t_graphics *g)
{
	int	x;
	int	y;

	x = g->inf->player.x;
	y = g->inf->player.y;
	if (g->inf->clean_map[x][y + 1] != '1')
	{
		if (g->inf->clean_map[x][y] == '0' || g->inf->clean_map[x][y] == 'P')
			mlx_put_image_to_window(g->p, g->w, g->s->f, y * PX, x * PX);
		if (g->inf->clean_map[x][y] == 'E' && g->inf->obj != 0)
			mlx_put_image_to_window(g->p, g->w, g->s->excl, y * PX, x * PX);
		g->inf->player.y += 1;
		y = g->inf->player.y;
		if (g->inf->clean_map[x][y] == 'C')
		{
			g->inf->obj--;
			g->inf->clean_map[x][y] = '0';
		}
		mlx_put_image_to_window(g->p, g->w, g->s->crash_r, y * PX, x * PX);
		g->inf->player.mov += 1;
		printf("Taps: %d\n", g->inf->player.mov);
	}
	check_exit(g);
}

void	move_character_a(t_graphics *g)
{
	int	x;
	int	y;

	x = g->inf->player.x;
	y = g->inf->player.y;
	if (g->inf->clean_map[x][y - 1] != '1')
	{
		if (g->inf->clean_map[x][y] == '0' || g->inf->clean_map[x][y] == 'P')
			mlx_put_image_to_window(g->p, g->w, g->s->wall, y * PX, x * PX);
		if (g->inf->clean_map[x][y] == 'E' && g->inf->obj != 0)
			mlx_put_image_to_window(g->p, g->w, g->s->excl, y * PX, x * PX);
		g->inf->player.y -= 1;
		y = g->inf->player.y;
		if (g->inf->clean_map[x][y] == 'C')
		{
			g->inf->obj--;
			g->inf->clean_map[x][y] = '0';
		}
		mlx_put_image_to_window(g->p, g->w, g->s->crash_l, y * PX, x * PX);
		g->inf->player.mov += 1;
		/* ft_printf("Taps: %d\n", g->inf->player.mov); */
	}
	check_exit(g);
}

void	move_character_w(t_graphics *g)
{
	int	x;
	int	y;

	x = g->inf->player.x;
	y = g->inf->player.y;
	if (g->inf->clean_map[x - 1][y] != '1')
	{
		if (g->inf->clean_map[x][y] == '0' || g->inf->clean_map[x][y] == 'P')
			mlx_put_image_to_window(g->p, g->w, g->s->f, y * PX, x * PX);
		if (g->inf->clean_map[x][y] == 'E' && g->inf->obj != 0)
			mlx_put_image_to_window(g->p, g->w, g->s->excl, y * PX, x * PX);
		g->inf->player.x -= 1;
		x = g->inf->player.x;
		if (g->inf->clean_map[x][y] == 'C')
		{
			g->inf->obj--;
			g->inf->clean_map[x][y] = '0';
		}
		mlx_put_image_to_window(g->p, g->w, g->s->crash_b, y * PX, x * PX);
		g->inf->player.mov += 1;
		/* ft_printf("Taps: %d\n", g->inf->player.mov); */
	}
	check_exit(g);
}

void	move_character_s(t_graphics *g)
{
	int	x;
	int	y;

	x = g->inf->player.x;
	y = g->inf->player.y;
	if (g->inf->clean_map[x + 1][y] != '1')
	{
		if (g->inf->clean_map[x][y] == '0' || g->inf->clean_map[x][y] == 'P')
			mlx_put_image_to_window(g->p, g->w, g->s->f, y * PX, x * PX);
		if (g->inf->clean_map[x][y] == 'E' && g->inf->obj != 0)
			mlx_put_image_to_window(g->p, g->w, g->s->excl, y * PX, x * PX);
		g->inf->player.x += 1;
		x = g->inf->player.x;
		if (g->inf->clean_map[x][y] == 'C')
		{
			g->inf->obj--;
			g->inf->clean_map[x][y] = '0';
		}
		mlx_put_image_to_window(g->p, g->w, g->s->crash_f, y * PX, x * PX);
		g->inf->player.mov += 1;
		/* ft_printf("Taps: %d\n", g->inf->player.mov); */
	}
	check_exit(g);
}