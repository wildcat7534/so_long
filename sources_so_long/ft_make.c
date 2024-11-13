/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:48:44 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 21:50:40 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_data(t_game *game)
{
	game->map_cpy = NULL;
	game->map.map = ft_split(game->map_line, '\n');
	ft_p_coor(game);
	ft_e_coor(game);
	game->nb_collectibles = 0;
	game->count_collectibles = ft_count_collect(game);
	game->map_cpy = ft_split(game->map_line, '\n');
	if (game->map.map == NULL || game->map_cpy == NULL)
	{
		ft_printf("Error\nmem alloc split error\n");
		free(game->map_line);
		ft_free_dtab(game->map.map);
		ft_free_dtab(game->map_cpy);
		exit(1);
	}
	if (ft_verif_p_e(game))
	{
		ft_printf("Error\ncharacters error\n");
		free(game->map_line);
		ft_free_dtab(game->map.map);
		ft_free_dtab(game->map_cpy);
		exit(1);
	}
	game->nb_moves = 0;
	game->map.width = 0;
	free(game->map_line);
}

void	ft_map_line(t_game *game)
{
	int	line_empty;

	line_empty = 0;
	game->map_line = ft_strdup("");
	while (game->line != NULL)
	{
		game->map_line = ft_strjoin(game->map_line, game->line);
		free(game->line);
		game->line = get_next_line(game->fd);
		if (game->line && game->line[0] && game->line[0] != '\n' && line_empty)
		{
			ft_printf("Error\nMap_line is not valid.\n");
			free(game->map_line);
			free(game->line);
			exit(1);
		}
		if (game->line && game->line[0] == '\n')
		{
			ft_printf("Error\nMap_line is empty.\n");
			line_empty = 1;
		}
	}
	ft_init_data(game);
}

int	ft_make_windows(t_game *game)
{
	game->window.width = game->map.width * TL;
	game->window.height = game->map.height * TL;
	game->data.mlx_ptr = mlx_init();
	if (!game->data.mlx_ptr)
		return (1);
	game->data.win_ptr = mlx_new_window(game->data.mlx_ptr, game->window.width,
			game->window.height, "so_long");
	if (!game->data.win_ptr)
	{
		ft_printf("Error\n* fail : mlx_new_window\n");
		ft_free_mlx(game);
		return (1);
	}
	close(game->fd);
	if (!game->data.win_ptr)
	{
		ft_free_mlx(game);
		return (1);
	}
	return (0);
}

void	ft_make_map(t_game *game)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	ft_init_img(game);
	while (game->map.map[i] != NULL)
	{
		ft_printer(game, game->map.map[i], x, y);
		y += TL;
		i++;
	}
	mlx_key_hook(game->data.win_ptr, &perso_keyhook, game);
	game->nb_collectibles = ft_count_collect(game);
	mlx_hook(game->data.win_ptr, 17, 0, &perso_mouse, game);
	mlx_loop(game->data.mlx_ptr);
	ft_free_mlx(game);
}
