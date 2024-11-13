/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:49:48 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 09:27:09 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_path(t_game *game)
{
	game->count_collectibles = 0;
	if (game->map_cpy == NULL)
		return (1);
	if (ft_collect_playable(game, game->player.y, game->player.x) == 0)
		return (0);
	ft_reset_map_cpy(game);
	if (!ft_exit_playable(game, game->player.y, game->player.x))
		return (0);
	return (1);
}

int	ft_collect_playable(t_game *game, int y, int x)
{
	int	ok;

	ok = 0;
	if (game->count_collectibles == game->nb_collectibles)
		return (1);
	if (y > 0 && game->map_cpy[y - 1][x] != '1' && game->map_cpy[y
		- 1][x] != 'V' && game->map_cpy[y - 1][x] != 'P' && ok == 0)
		ok = ft_collect_moves(game, y - 1, x);
	if (game->map_cpy[y][x + 1] != '1' && game->map_cpy[y][x + 1] != 'V'
		&& game->map_cpy[y][x + 1] != 'P' && ok == 0)
		ok = ft_collect_moves(game, y, x + 1);
	if (game->map_cpy[y + 1][x] != '1' && game->map_cpy[y + 1][x] != 'V'
		&& game->map_cpy[y + 1][x] != 'P' && ok == 0)
		ok = ft_collect_moves(game, y + 1, x);
	if (x > 0 && game->map_cpy[y][x - 1] != '1' && game->map_cpy[y][x
		- 1] != 'V' && game->map_cpy[y][x - 1] != 'P' && ok == 0)
		ok = ft_collect_moves(game, y, x - 1);
	if (ok == 1)
		return (1);
	return (0);
}

int	ft_collect_moves(t_game *game, int y, int x)
{
	if (game->map_cpy[y][x] == 'C')
		game->count_collectibles++;
	if (game->map_cpy[y][x] == 'C' || game->map_cpy[y][x] == '0')
		game->map_cpy[y][x] = 'V';
	return (ft_collect_playable(game, y, x));
}

int	ft_exit_playable(t_game *game, int y, int x)
{
	int	ok;

	ok = 0;
	if (game->map_cpy[y][x] == 'E')
		return (1);
	if (game->map_cpy[y - 1][x] != '1' && game->map_cpy[y - 1][x] != 'V'
		&& game->map_cpy[y - 1][x] != 'P' && ok == 0)
		ok = ft_exit_moves(game, y - 1, x);
	if (game->map_cpy[y][x + 1] != '1' && game->map_cpy[y][x + 1] != 'V'
		&& game->map_cpy[y][x + 1] != 'P' && ok == 0)
		ok = ft_exit_moves(game, y, x + 1);
	if (game->map_cpy[y + 1][x] != '1' && game->map_cpy[y + 1][x] != 'V'
		&& game->map_cpy[y + 1][x] != 'P' && ok == 0)
		ok = ft_exit_moves(game, y + 1, x);
	if (game->map_cpy[y][x - 1] != '1' && game->map_cpy[y][x - 1] != 'V'
		&& game->map_cpy[y][x - 1] != 'P' && ok == 0)
		ok = ft_exit_moves(game, y, x - 1);
	if (ok == 1)
		return (1);
	return (0);
}

int	ft_exit_moves(t_game *game, int y, int x)
{
	if (game->map_cpy[y][x] == 'C' || game->map_cpy[y][x] == '0')
		game->map_cpy[y][x] = 'V';
	return (ft_exit_playable(game, y, x));
}
