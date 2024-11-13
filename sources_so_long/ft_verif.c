/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:53:35 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 21:49:26 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_verif_file(int argc, char *argv)
{
	int	len;

	len = 0;
	if (argc != 2)
	{
		ft_printf("Error\nYou must hade a map in one argument\n");
		return (1);
	}
	else
	{
		len = ft_strlen(argv);
		if (len == 0)
			ft_printf("Error\nmap path empty\n");
		if (ft_strncmp(&argv[len - 4], ".ber", 4) || len < 5)
		{
			ft_printf("Error\nmap file invalide\n");
			return (1);
		}
	}
	return (0);
}


int	ft_verif_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (game->map.map[0][x] != '\0')
	{
		if (game->map.map[0][x] != '1')
			return (1);
		x++;
		game->map.width++;
	}
	while (game->map.map[y] != NULL)
	{
		if (game->map.map[y][0] != '1')
			return (1);
		game->map.height++;
		y++;
	}
	if (ft_verif_wall2(game, y))
		return (1);
	return (0);
}

int	ft_verif_wall2(t_game *game, int y)
{
	int	x;

	x = 0;
	while (game->map.map[y - 1][x] != '\0')
	{
		if (game->map.map[y - 1][x] != '1')
			return (1);
		x++;
	}
	y = 0;
	while (game->map.map[y] != NULL)
	{
		if (game->map.map[y][x - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	ft_size_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y] != NULL)
	{
		x = 0;
		while (game->map.map[y][x] != '\0')
			x++;
		if (x != game->map.width)
			return (1);
		y++;
	}
	return (0);
}

int	ft_check_max(t_game *game)
{
	if (ft_verif_wall(game) || ft_verif_all_char(game) || ft_size_map(game))
	{
		ft_printf("Error\nMap is not valid.\n");
		return (1);
	}
	else if (!ft_count_collect(game))
	{
		ft_printf("Error\nNo collectible\n");
		return (1);
	}
	else if (ft_verif_p_e(game))
	{
		ft_printf("Error\nPlayer or Exit > 1\n");
		return (1);
	}
	else if (!ft_check_path(game))
	{
		ft_printf("Error\nMap isn't possible\n");
		return (1);
	}
	ft_printf("Map is valid\n");
	ft_free_dtab(game->map_cpy);
	return (0);
}
