/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 06:10:17 by abastard          #+#    #+#             */
/*   Updated: 2025/02/05 07:58:47 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_sprites()
{
    if (open(ROCK, O_RDONLY) == -1 || open(PATH, O_RDONLY) == -1 
		|| open(CRASHBACK, O_RDONLY) == -1 || open(GRASS, O_RDONLY) == -1
		|| open(MASK, O_RDONLY) == -1 || open(APPLE, O_RDONLY) == -1
		|| open(CRASHFRONT, O_RDONLY) == -1 || open(CRASHLEFT, O_RDONLY) == -1
		|| open(CRASHRIGHT, O_RDONLY) == -1)
		{
			printf("me aseguro que paso por aqui\n");
		return (1);
		}
	else
		return (0);
}

static int	load_background(t_graphics *g, t_sprites *s)
{
    int	x;
	int	y;

	x = PX;
	y = PX;
	g->s->wall = mlx_xpm_file_to_image(g->p, GRASS, &x, &y);
	if (!s->wall)
		return (1);
	s->apple = mlx_xpm_file_to_image(g->p, APPLE, &x, &y);
	if (!s->apple)
		return (1);
	s->excl = mlx_xpm_file_to_image(g->p, ROCK, &x, &y);
	if (!s->excl)
		return (1);
	s->exit_op = mlx_xpm_file_to_image(g->p, MASK, &x, &y);
	if (!s->exit_op)
		return (1);
	s->f = mlx_xpm_file_to_image(g->p, PATH, &x, &y);
	if (!s->f)
		return (1);
	return (0);

}

void	load_sprites(t_graphics *g, t_sprites *s)
{
    check_sprites(g);
	load_background(g, s);
	return ;
}

void	init_image(t_graphics *g, t_sprites *s)
{
    int	i;
	int	j;

	load_sprites(g, s);
	j = 0;
	while (g->inf->clean_map[j])
	{
		i = -1;
		while (g->inf->clean_map[j][++i])
		{
			if (g->inf->clean_map[j][i] == '1')
				mlx_put_image_to_window(g->p, g->w, s->wall, i * PX, j * PX);
			else if (g->inf->clean_map[j][i] == '0')
				mlx_put_image_to_window(g->p, g->w, s->f, i * PX, j * PX);
			else if (g->inf->clean_map[j][i] == 'E')
				mlx_put_image_to_window(g->p, g->w, s->excl, i * PX, j * PX);
			else if (g->inf->clean_map[j][i] == 'P')
				mlx_put_image_to_window(g->p, g->w, s->crash_r, i * PX, j * PX);
			else if (g->inf->clean_map[j][i] == 'C')
				mlx_put_image_to_window(g->p, g->w, s->apple, i * PX, j * PX);
		}
		j++;
	}
	return ;
}