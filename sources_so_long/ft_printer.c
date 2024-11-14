/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:28:01 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 20:48:47 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_printer(t_game *g, char *line, int x, int y)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr,
			g->img.floor, x, y);
		if (line[i] == '1')
			mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr,
				g->img.wall, x, y);
		else if (line[i] == 'P')
			mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr,
				g->img.player, x, y);
		else if (line[i] == 'E')
			mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr,
				g->img.exit, x, y);
		else if (line[i] == 'C')
			mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr,
				g->img.item, x, y);
		x += TL;
		i++;
	}
}

void	game_over(t_game *g)
{
	mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr,
		g->img.exit_no, g->p.x * 55, g->p.y * 55);
	if (g->nb_collectibles == g->count_collectibles)
	{
		ft_printf("****[~][~]WiNNeR[~][~]****\n", 0);
		ft_free_mlx(g);
		//free(g->d.mlx_ptr);
		exit(0);
	}
}
