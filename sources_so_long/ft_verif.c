/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:53:35 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 22:09:59 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_verif_file(int argc, char *argv)
{
	int	len;

	len = 0;
	if (argc != 2)
	{
		write(2, "Error\nYou must hade a map in one argument\n", 42);
		return (1);
	}
	else
	{
		len = ft_strlen(argv);
		if (len == 0)
			write(2, "Error\nmap path empty\n", 21);
		if (ft_strncmp(&argv[len - 4], ".ber", 4) || len < 5)
		{
			write(2, "Error\nmap file invalide\n", 24);
			return (1);
		}
	}
	return (0);
}

int	ft_verif_wall(t_game *g)
{
	int	x;
	int	y;

	g->map.width = 0;
	y = 0;
	x = 0;
	while (g->map.map[0][x] != '\0')
	{
		if (g->map.map[0][x] != '1')
			return (1);
		x++;
		g->map.width++;
	}
	while (g->map.map[y] != NULL)
	{
		if (g->map.map[y][0] != '1')
			return (1);
		g->map.height++;
		y++;
	}
	if (ft_verif_wall2(g, y))
		return (1);
	return (0);
}

int	ft_verif_wall2(t_game *g, int y)
{
	int	x;

	x = 0;
	while (g->map.map[y - 1][x] != '\0')
	{
		if (g->map.map[y - 1][x] != '1')
			return (1);
		x++;
	}
	y = 0;
	while (g->map.map[y] != NULL)
	{
		if (g->map.map[y][x - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	ft_size_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map.map[y] != NULL)
	{
		x = 0;
		while (g->map.map[y][x] != '\0')
			x++;
		if (x != g->map.width)
			return (1);
		y++;
	}
	return (0);
}

int	ft_check_max(t_game *g)
{
	if (ft_verif_wall(g) || ft_verif_all_char(g) || ft_size_map(g))
	{
		write(2, "Error\nMap is not valid.\n", 24);
		ft_free_dtab(g->map_cpy);
		ft_free_dtab(g->map.map);
		exit(0);
		return (1);
	}
	else if (!ft_count_collect(g))
	{
		write(2, "Error\nNo collectible\n", 22);
		ft_free_dtab(g->map_cpy);
		ft_free_mlx(g);
		exit(0);
		return (1);
	}
	else if (ft_verif_p_e(g))
	{
		write(2, "Error\nPlayer or Exit > 1\n", 25);
		ft_free_dtab(g->map_cpy);
		ft_free_mlx(g);
		exit(0);
		return (1);
	}
	else if (!ft_check_path(g))
	{
		write(2, "Error\nMap isn't possible or not valid \n", 40);
		ft_free_dtab(g->map_cpy);
		ft_free_dtab(g->map.map);
		exit(0);
		return (1);
	}
	ft_free_dtab(g->map_cpy);
	return (0);
}
