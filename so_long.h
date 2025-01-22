/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:19:06 by abastard          #+#    #+#             */
/*   Updated: 2025/01/21 17:39:45 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/* ···· libraries ···· */
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* ···· size ···· */
# define PX 50

/* ···· sprites route ···· */
# define PATH "assets/path.xpm"
# define GRASS "assets/Grass.xpm"
# define APPLE "assets/collectable.xpm"
# define ROCK "assets/rock.xpm"
# define MASK "assets/mask.xpm"
# define CRASHFRONT "assets/crash_front.xpm"
# define CRASHBACK "assets/crash_back.xpm"
# define CRASHRIGHT "assets/crash_right.xpm"
# define CRASHLEFT "assets/crash_left.xpm"

/* ····· keybinds ····· */
# define ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0 
# define KEY_D 2
# define KEY_S 1
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_DOWN 125

typedef struct s_sprites
{
	void		*f;
	void		*wall;
	void		*apple;
	void		*excl;
	void		*exit_op;
	void		*crash_f;
	void		*crash_b;
	void		*crash_l;
	void		*crash_r;
}	t_sprites;

typedef struct s_player
{
	int	x;
	int	y;
	int	mov;
	int	obj;
}	t_player;

typedef struct s_exit
{
	int			x;
	int			y;
}	t_exit;

typedef struct s_parsemap
{
	char		**clean_map;
	char		**map;
	int			w_x;
	int			w_y;
	int			fd;
	int			obj;
	int			obj_check;
	int			exit_check;
	int			exit_num;
	int			player_num;
	t_player	player;
	t_exit		exit;
}	t_parsemap;

typedef struct s_graphics
{
	t_sprites	*s;
	t_parsemap	*inf;
	void		*p;
	void		*w;
}	t_graphics;

// INIT
t_parsemap		*init_struct(void);

// PARSE
int				parse_map(char *argv, t_parsemap **mapinf);

//UTILS
int	ft_strncmpend(char *s1, char *s2, int n);
#endif