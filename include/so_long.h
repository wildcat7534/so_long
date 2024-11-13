/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:23:38 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 08:57:07 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>

typedef struct s_player
{
	int				x;
	int				y;
}					t_player;

typedef struct s_collectible
{
	int				x;
	int				y;
}					t_collectible;

typedef struct s_exit
{
	int				x;
	int				y;
}					t_exit;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}					t_map;

typedef struct s_img
{
	void			*mlx_img;
	void			*floor;
	void			*wall;
	void			*player;
	void			*exit_no;
	void			*exit;
	void			*item;
}					t_img;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_data;

typedef struct s_window
{
	int				width;
	int				height;
}					t_window;

typedef struct s_game
{
	t_data			data;
	t_map			map;
	t_player		player;
	t_img			img;
	t_collectible	*collectibles;
	t_exit			exit;
	t_window		window;
	char			*line;
	char			*map_line;
	char			**map_cpy;
	int				fd;
	int				nb_collectibles;
	int				count_collectibles;
	int				nb_moves;
	int				nb_exits;
}					t_game;

/*int					handle_no_event(void *data);
void				img_pixel_put(t_game *game, int x, int y, int color);
void				free_mlx(t_game *game);
int					render(t_game *game);
int					render_map(t_game *game);
int					handle_input(t_game *game, int keysym);
int					update_player(t_game *game, int keysym);
void				init_game(t_game *game);
void				init_map(t_map *map);
void				init_player(t_player *player);
void				render_player(t_game *game);
void	init_collectibles(t_collectible *collectibles,
						int nb_collectibles);
void				init_exits(t_exit *exits, int nb_exits);
int	load_map(t_map *map, char *filename);*/
int					ft_verif_map(t_game *game);
int					ft_verif_wall(t_game *game);
int					ft_verif_wall2(t_game *game, int y);
int					ft_verif_p_e(t_game *game);
void				ft_e_coor(t_game *game);
void				ft_p_coor(t_game *game);
int					ft_verif_all_char(t_game *game);
int					ft_count_collect(t_game *game);
int					ft_collect_playable(t_game *game, int y, int x);
int					ft_exit_playable(t_game *game, int y, int x);
int					ft_collect_moves(t_game *game, int y, int x);
int					ft_exit_moves(t_game *game, int y, int x);
void				ft_destroy_img(t_game *game);
void				ft_free_mlx(t_game *game);
void				ft_free_dtab(char **dtab);
int					ft_verif_file(int argc, char *argv);
void				ft_map_line(t_game *game);
void				ft_make_map(t_game *game);
int					ft_make_windows(t_game *game);
void				ft_init_img(t_game *game);
void				ft_reset_map_cpy(t_game *game);
int					ft_check_max(t_game *game);
int					ft_check_path(t_game *game);
void				ft_printer(t_game *game, char *line, int x, int y);
int					perso_keyhook(int keysym, t_game *game);
int					perso_mouse(t_game *game);
void				ft_move_left(t_game *game);
void				ft_move_right(t_game *game);
void				ft_move_up(t_game *game);
void				ft_move_down(t_game *game);
void				game_over(t_game *game);

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define RED_PIXEL 0x00FF0000
# define GREEN_PIXEL 0x0000FF00
# define BLUE_PIXEL 0x000000FF
# define WHITE_PIXEL 0x00FFFFFF
# define BLACK_PIXEL 0x00000000
# define YELLOW_PIXEL 0x00FFFF00
# define TL 55

#endif
