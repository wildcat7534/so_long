/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 04:17:09 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 04:33:38 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_count_collect(t_game *game)
{
	int	x;
	int	y;
	int	nb;

	y = 0;
	nb = 0;
	while (game->map.map[y] != NULL)
	{
		x = 0;
		while (game->map.map[y][x] != '\0')
		{
			if (game->map.map[y][x] == 'C')
				nb++;
			x++;
		}
		y++;
	}
	return (nb);
}

int	ft_verif_all_char(t_game *game)
{
	int	x;
	int	y;
	int	check;

	y = 0;
	while (game->map.map[y] != NULL)
	{
		x = 0;
		while (game->map.map[y][x] != '\0')
		{
			check = game->map.map[y][x];
			if (check != '1' && check != '0' && check != 'P' && check != 'C'
				&& check != 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_verif_p_e(t_game *game)
{
	int	x;
	int	y;
	int	position;
	int	exit;

	y = 0;
	position = 0;
	exit = 0;
	while (game->map.map[y] != NULL)
	{
		x = 0;
		while (game->map.map[y][x] != '\0')
		{
			if (game->map.map[y][x] == 'P')
				position++;
			if (game->map.map[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (position != 1 || exit != 1)
		return (1);
	return (0);
}

