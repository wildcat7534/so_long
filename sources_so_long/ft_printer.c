/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:28:01 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 09:30:49 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_printer(t_game *game, char *line, int x, int y)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.floor, x, y);
		if (line[i] == '1')
			mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
				game->img.wall, x, y);
		else if (line[i] == 'P')
			mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
				game->img.player, x, y);
		else if (line[i] == 'E')
			mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
				game->img.exit, x, y);
		else if (line[i] == 'C')
			mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
				game->img.item, x, y);
		x += TL;
		i++;
	}
}

void	game_over(t_game *game)
{
	mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
		game->img.exit_no, game->player.x * 55, game->player.y * 55);
	if (game->nb_collectibles == game->count_collectibles)
	{
		ft_printf("****[~][~]WiNNeR[~][~]****\n", 0);
		ft_free_mlx(game);
		exit(0);
		free(game->data.mlx_ptr);
	}
}
