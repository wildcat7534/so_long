/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:49:48 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 22:57:50 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_path(t_game *g)
{
	g->count_collectibles = 0;
	if (g->map_cpy == NULL)
		return (0);
	if (ft_collect_playable(g, g->p.y, g->p.x) == 0)
		return (0);
	ft_reset_map_cpy(g);
	if (!ft_exit_playable(g, g->p.y, g->p.x))
		return (0);
	return (1);
}

int	ft_collect_playable(t_game *g, int y, int x)
{
	int	ok;

	ok = 0;
	if (g->count_collectibles == g->nb_collectibles)
		return (1);
	if (g->map_cpy[y - 1][x] != '1' && g->map_cpy[y
		- 1][x] != 'V' && g->map_cpy[y - 1][x] != 'P' && ok == 0)
		ok = ft_collect_moves(g, y - 1, x);
	if (g->map_cpy[y][x + 1] != '1' && g->map_cpy[y][x + 1] != 'V'
		&& g->map_cpy[y][x + 1] != 'P' && ok == 0)
		ok = ft_collect_moves(g, y, x + 1);
	if (g->map_cpy[y + 1][x] != '1' && g->map_cpy[y + 1][x] != 'V'
		&& g->map_cpy[y + 1][x] != 'P' && ok == 0)
		ok = ft_collect_moves(g, y + 1, x);
	if (g->map_cpy[y][x - 1] != '1' && g->map_cpy[y][x
		- 1] != 'V' && g->map_cpy[y][x - 1] != 'P' && ok == 0)
		ok = ft_collect_moves(g, y, x - 1);
	if (ok == 1)
		return (1);
	return (0);
}

int	ft_collect_moves(t_game *g, int y, int x)
{
	if (g->map_cpy[y][x] == 'C')
		g->count_collectibles++;
	if (g->map_cpy[y][x] == 'C' || g->map_cpy[y][x] == '0')
		g->map_cpy[y][x] = 'V';
	return (ft_collect_playable(g, y, x));
}

int	ft_exit_playable(t_game *g, int y, int x)
{
	int	ok;

	ok = 0;
	if (g->map_cpy[y][x] == 'E')
		return (1);
	if (y > 0 && g->map_cpy[y - 1][x] != '1' && g->map_cpy[y - 1][x] != 'V'
		&& g->map_cpy[y - 1][x] != 'P' && ok == 0)
		ok = ft_exit_moves(g, y - 1, x);
	if (g->map_cpy[y][x + 1] != '1' && g->map_cpy[y][x + 1] != 'V'
		&& g->map_cpy[y][x + 1] != 'P' && ok == 0)
		ok = ft_exit_moves(g, y, x + 1);
	if (g->map_cpy[y + 1][x] != '1' && g->map_cpy[y + 1][x] != 'V'
		&& g->map_cpy[y + 1][x] != 'P' && ok == 0)
		ok = ft_exit_moves(g, y + 1, x);
	if (x > 0 && g->map_cpy[y][x - 1] != '1' && g->map_cpy[y][x - 1] != 'V'
		&& g->map_cpy[y][x - 1] != 'P' && ok == 0)
		ok = ft_exit_moves(g, y, x - 1);
	if (ok == 1)
		return (1);
	return (0);
}

int	ft_exit_moves(t_game *g, int y, int x)
{
	if (g->map_cpy[y][x] == 'C' || g->map_cpy[y][x] == '0')
		g->map_cpy[y][x] = 'V';
	return (ft_exit_playable(g, y, x));
}
