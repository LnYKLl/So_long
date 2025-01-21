/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:16:26 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/21 02:25:35 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# if BUFFER_SIZE > 1024
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_map
{
	int		width;
	int		height;
}			t_map;

typedef struct s_image
{
	void	*xpm;
	int		x;
	int		y;
}			t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_map	map_size;
	t_image	background;
	t_image	wall;
	t_image	coins;
	t_image	player;
	int		width;
	int		height;
	int		moves;
}			t_game;

char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);

int			close_window(t_game *vars);
int			key_hook(int keycode, t_game *vars);
int			game_loop(char **argv);
void		draw_background(t_game *vars, int x, int y);
void		draw_wall(t_game *vars, int x, int y);
void		init_sprites(t_game *vars);
void		draw_player(t_game *vars, int x, int y);
int			check_map(char **argv);
#endif