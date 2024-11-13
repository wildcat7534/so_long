/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:28:44 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 09:33:19 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	perso_keyhook(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		ft_free_mlx(game);
		exit(0);
	}
	if (keysym == XK_w || keysym == XK_Up)
		ft_move_up(game);
	if (keysym == XK_s || keysym == XK_Down)
		ft_move_down(game);
	if (keysym == XK_a || keysym == XK_Left)
		ft_move_left(game);
	if (keysym == XK_d || keysym == XK_Right)
		ft_move_right(game);
	return (0);
}

void	ft_move_left(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x - 1] == '1')
	{
		ft_printf("Error,\nWall\n", 0);
	}
	else if (game->map.map[game->player.y][game->player.x] == 'E')
	{
		game->nb_moves++;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.exit, game->player.x * TL, game->player.y * TL);
		game->player.x--;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.player, game->player.x * TL, game->player.y * TL);
	}
	else
	{
		game->nb_moves++;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.floor, game->player.x * TL, game->player.y * TL);
		game->player.x--;
		if (game->map.map[game->player.y][game->player.x] == 'E')
			game_over(game);
		else
		{
			mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
				game->img.player, game->player.x * TL, game->player.y * TL);
		}
	}
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->count_collectibles++;
		game->map.map[game->player.y][game->player.x] = '0';
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x + 1] == '1')
	{
		ft_printf("Error,\nWall\n", 0);
	}
	else if (game->map.map[game->player.y][game->player.x] == 'E')
	{
		game->nb_moves++;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.exit, game->player.x * TL, game->player.y * TL);
		game->player.x++;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.player, game->player.x * TL, game->player.y * TL);
	}
	else
	{
		game->nb_moves++;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.floor, game->player.x * TL, game->player.y * TL);
		game->player.x++;
		if (game->map.map[game->player.y][game->player.x] == 'E')
			game_over(game);
		else
			mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
				game->img.player, game->player.x * TL, game->player.y * TL);
	}
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->count_collectibles++;
		game->map.map[game->player.y][game->player.x] = '0';
	}
}

void	ft_move_up(t_game *game)
{
	if (game->map.map[game->player.y - 1][game->player.x] == '1')
		ft_printf("Error,\nWall\n", 0);
	else if (game->map.map[game->player.y][game->player.x] == 'E')
	{
		game->nb_moves++;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.exit, game->player.x * TL, game->player.y * TL);
		game->player.y--;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.player, game->player.x * TL, game->player.y * TL);
	}
	else
	{
		game->nb_moves++;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.floor, game->player.x * TL, game->player.y * TL);
		game->player.y--;
		if (game->map.map[game->player.y][game->player.x] == 'E')
			game_over(game);
		else
			mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
				game->img.player, game->player.x * TL, game->player.y * TL);
	}
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->count_collectibles++;
		game->map.map[game->player.y][game->player.x] = '0';
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map.map[game->player.y + 1][game->player.x] == '1')
		ft_printf("Error,\nWall\n", 0);
	else if (game->map.map[game->player.y][game->player.x] == 'E')
	{
		game->nb_moves++;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.exit, game->player.x * TL, game->player.y * TL);
		game->player.y++;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.player, game->player.x * TL, game->player.y * TL);
	}
	else
	{
		game->nb_moves++;
		mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
			game->img.floor, game->player.x * TL, game->player.y * TL);
		game->player.y++;
		if (game->map.map[game->player.y][game->player.x] == 'E')
			game_over(game);
		else
			mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr,
				game->img.player, game->player.x * TL, game->player.y * TL);
	}
	if (game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->count_collectibles++;
		game->map.map[game->player.y][game->player.x] = '0';
	}
}
