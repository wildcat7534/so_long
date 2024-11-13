/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:17:04 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 21:46:25 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_mlx(t_game *game)
{
	ft_destroy_img(game);
	if (game->data.mlx_ptr != NULL)
		mlx_loop_end(game->data.mlx_ptr);
	if (game->data.win_ptr != NULL)
	{
		mlx_clear_window(game->data.mlx_ptr, game->data.win_ptr);	
		mlx_destroy_window(game->data.mlx_ptr, game->data.win_ptr);
	}
	if (game->data.mlx_ptr != NULL)
	{
		mlx_destroy_display(game->data.mlx_ptr);
		free(game->data.mlx_ptr);
	}
	//ft_free_dtab(game->map.map);
	//ft_free_dtab(game->map_cpy);
	exit(0);
}

void	ft_destroy_img(t_game *game)
{
	if (game->img.wall)
		mlx_destroy_image(game->data.mlx_ptr, game->img.wall);
	if (game->img.floor)
		mlx_destroy_image(game->data.mlx_ptr, game->img.floor);
	if (game->img.player)
		mlx_destroy_image(game->data.mlx_ptr, game->img.player);
	if (game->img.item)
		mlx_destroy_image(game->data.mlx_ptr, game->img.item);
	if (game->img.exit)
		mlx_destroy_image(game->data.mlx_ptr, game->img.exit);
	if (game->img.exit_no)
		mlx_destroy_image(game->data.mlx_ptr, game->img.exit_no);
}

void	ft_reset_map_cpy(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map_cpy[y] != NULL)
	{
		x = 0;
		while (game->map_cpy[y][x] != '\0')
		{
			if (game->map_cpy[y][x] == 'V')
				game->map_cpy[y][x] = '0';
			x++;
		}
		y++;
	}
}