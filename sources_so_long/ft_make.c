/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:48:44 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 06:25:34 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_data(t_game *g)
{
	g->map_cpy = NULL;
	g->map.map = ft_split(g->map_line, '\n');
	ft_p_coor(g);
	ft_e_coor(g);
	g->nb_collectibles = 0;
	g->count_collectibles = ft_count_collect(g);
	g->map_cpy = ft_split(g->map_line, '\n');
	if (g->map.map == NULL || g->map_cpy == NULL)
	{
		write(2, "Error\nmem alloc split error\n", 28);
		free(g->map_line);
		ft_free_dtab(g->map.map);
		ft_free_dtab(g->map_cpy);
		exit(1);
	}
	if (ft_verif_p_e(g))
	{
		write(2, "Error\ncharacters error\n", 24);
		free(g->map_line);
		ft_free_dtab(g->map.map);
		ft_free_dtab(g->map_cpy);
		exit(1);
	}
	g->nb_moves = 0;
	free(g->map_line);
}

void	ft_map_line(t_game *g)
{
	int	line_empty;

	line_empty = 0;
	g->map_line = ft_strdup("");
	while (g->line != NULL)
	{
		g->map_line = ft_strjoin(g->map_line, g->line);
		free(g->line);
		g->line = get_next_line(g->fd);
		if (g->line && g->line[0] && g->line[0] != '\n' && line_empty)
		{
			write(2, "Error\nMap_line is not valid.\n", 29);
			free(g->map_line);
			free(g->line);
			exit(1);
		}
		if (g->line && g->line[0] == '\n')
		{
			write(2, "Error\nMap_line is empty.\n", 26);
			line_empty = 1;
		}
	}
	ft_init_data(g);
}

int	ft_make_windows(t_game *g)
{
	g->window.width = g->map.width * TL;
	g->window.height = g->map.height * TL;
	g->d.mlx_ptr = mlx_init();
	if (!g->d.mlx_ptr)
		return (1);
	g->d.win_ptr = mlx_new_window(g->d.mlx_ptr, g->window.width,
			g->window.height, "Pelufa&Fofina");
	if (!g->d.win_ptr)
	{
		write(2, "Error\n* fail : mlx_new_window\n", 31);
		ft_free_mlx(g);
		return (1);
	}
	close(g->fd);
	if (!g->d.win_ptr)
	{
		ft_free_mlx(g);
		return (1);
	}
	return (0);
}

void	ft_make_map(t_game *g)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	ft_init_img(g);
	while (g->map.map[i] != NULL)
	{
		ft_printer(g, g->map.map[i], x, y);
		y += TL;
		i++;
	}
	mlx_key_hook(g->d.win_ptr, &perso_keyhook, g);
	g->nb_collectibles = ft_count_collect(g);
	mlx_hook(g->d.win_ptr, 17, 0, &perso_mouse, g);
	mlx_loop(g->d.mlx_ptr);
	ft_free_mlx(g);
}
