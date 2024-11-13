/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 04:03:54 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/12 17:41:53 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_p_coor(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	while (game->map.map[game->player.y][game->player.x] != 'P')
	{
		if (game->map.map[game->player.y][game->player.x] == '\0')
		{
			game->player.y++;
			game->player.x = 0;
		}
		else
			game->player.x++;
	}
}
void	ft_e_coor(t_game *game)
{
	game->exit.x = 0;
	game->exit.y = 0;
	while (game->map.map[game->exit.y][game->exit.x] != 'E')
	{
		if (game->map.map[game->exit.y][game->exit.x] == '\0')
		{
			game->exit.y++;
			game->exit.x = 0;
		}
		else
			game->exit.x++;
	}
}
