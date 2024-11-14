/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 04:03:54 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 22:44:08 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_count_size(t_game *g)
{
	int	x;
	int	y;

	g->map.width = 0;
	g->map.height = 0;
	y = 0;
	x = 0;
	while (g->map.map[0][x] != '\0')
	{
		if (g->map.map[0][x] != '1')
			break;
		x++;
		g->map.width++;
	}
	while (g->map.map[y] != NULL)
	{
		if (g->map.map[y][0] != '1')
			break;
		g->map.height++;
		y++;
	}
}

void	ft_p_coor(t_game *g)
{
	g->p.x = 0;
	g->p.y = 0;
	ft_count_size(g);
	
	while (g->map.map[g->p.y][g->p.x] != 'P')
	{
		if (g->map.map[g->p.y][g->p.x] == '\0')
		{
			if (g->p.y == g->map.height)
				return ;
			g->p.x = 0;
			g->p.y++;
		}
		g->p.x++;
	}
}

void	ft_e_coor(t_game *g)
{
	g->exit.x = 0;
	g->exit.y = 0;
	while (g->map.map[g->exit.y][g->exit.x] != 'E')
	{
		if (g->map.map[g->exit.y][g->exit.x] == '\0')
		{
			if (g->exit.y == g->map.height)
				return ;
			g->exit.y++;
			g->exit.x = 0;
		}
		else
			g->exit.x++;
	}
}
