/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 04:03:54 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 06:16:01 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_p_coor(t_game *g)
{
	g->p.x = 0;
	g->p.y = 0;
	while (g->map.map[g->p.y][g->p.x] != 'P' && g->map.map[g->p.y][g->p.x] != '\0')
	{
		if (g->map.map[g->p.y][g->p.x] == '\0')
		{
			g->p.y++;
			g->p.x = 0;
		}
		else
			g->p.x++;
	}
}

void	ft_e_coor(t_game *g)
{
	g->exit.x = 0;
	g->exit.y = 0;
	while (g->map.map[g->exit.y][g->exit.x] != 'E' && g->map.map[g->exit.y][g->exit.x] != '\0')
	{
		if (g->map.map[g->exit.y][g->exit.x] == '\0')
		{
			g->exit.y++;
			g->exit.x = 0;
		}
		else
			g->exit.x++;
	}
}
