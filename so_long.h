/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:19:06 by abastard          #+#    #+#             */
/*   Updated: 2025/01/25 16:13:52 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* ···· libraries ···· */
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

/* ···· size ···· */
/* # define PX 50 */

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
int		ft_strncmpend(char *s1, char *s2, int n);
char	*get_next_line(int fd);
int	ft_strlen(char *s);
int ft_strlen_mod(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *leftovers, char *buff);
char	*ft_get_line(char *leftovers);
char	*ft_leftovers(char *leftovers);
char	*ft_strdup(char *s);
char	*ft_read(int fd, char *text);
char *ft_strjoin_mod(char *str1, char *str2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif