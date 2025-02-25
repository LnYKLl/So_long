/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:16:26 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/25 19:17:55 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_map
{
	int			width;
	int			height;
	int			collectibles;
	int			exit;
	char		**map;
	int			exit_x;
	int			exit_y;
}				t_map;

typedef struct s_image
{
	void		*xpm;
	int			x;
	int			y;
}				t_image;

typedef struct s_sprite
{
	t_image		background;
	t_image		wall;
	t_image		coins;
	t_image		exit;
	t_image		player;
}				t_sprite;

typedef struct s_player
{
	int			x;
	int			y;
	int			old_x;
	int			old_y;
	int			moves;
	int			players;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_map		map_copy;
	t_player	player;
	t_sprite	sprite;
	int			width;
	int			height;
	int			moves;
}				t_game;

int				close_window(t_game *vars);
int				key_hook(int keycode, t_game *vars);
int				game_loop(char **argv);
void			vars_init(t_game *vars);
void			vars_sprites(t_game *vars);

void			draw_background(t_game *vars, int x, int y);
void			draw_wall(t_game *vars, int x, int y);
void			draw_coins(t_game *vars, int x, int y);
void			draw_map(t_game *vars, char **argv);
void			draw_exit(t_game *vars, int x, int y);
int				init_sprites(t_game *vars);
void			draw_player(t_game *vars, int x, int y);
void			display_moves(t_game *vars);

int				check_map(t_game *vars, char **argv);
int				render_map(t_game *vars, char **argv);
int				map_parsing(t_game *vars, char **argv);
void			draw_line(t_game *vars, char *line, int j);
int				map_read(t_game *vars, char **argv);
int				map_copy(t_game *vars);
void			path_alg(t_game *vars, int x, int y);
int				check_path(t_game *vars);
int				map_checker(t_game *vars, int fd, char *line, int line_length);

#endif