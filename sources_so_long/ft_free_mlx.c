/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:17:04 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 21:07:52 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_mlx(t_game *g)
{
	if (g->d.win_ptr != NULL)
	{
		mlx_destroy_window(g->d.mlx_ptr, g->d.win_ptr);
		//mlx_clear_window(g->d.mlx_ptr, g->d.win_ptr);
	}
	ft_destroy_img(g);
	mlx_destroy_display(g->d.mlx_ptr);
	if (g->map.map != NULL)
		ft_free_dtab(g->map.map);
	free(g->d.mlx_ptr);
	
/* 	if (g->d.mlx_ptr != NULL)
		mlx_loop_end(g->d.mlx_ptr); */
/* 	if (g->map_cpy != NULL)
		ft_free_dtab(g->map_cpy); */
	//free(g->d.mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	ft_destroy_img(t_game *g)
{
	if (g->img.wall)
		mlx_destroy_image(g->d.mlx_ptr, g->img.wall);
	if (g->img.floor)
		mlx_destroy_image(g->d.mlx_ptr, g->img.floor);
	if (g->img.player)
		mlx_destroy_image(g->d.mlx_ptr, g->img.player);
	if (g->img.item)
		mlx_destroy_image(g->d.mlx_ptr, g->img.item);
	if (g->img.exit)
		mlx_destroy_image(g->d.mlx_ptr, g->img.exit);
	if (g->img.exit_no)
		mlx_destroy_image(g->d.mlx_ptr, g->img.exit_no);
}

void	ft_reset_map_cpy(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map_cpy[y] != NULL)
	{
		x = 0;
		while (g->map_cpy[y][x] != '\0')
		{
			if (g->map_cpy[y][x] == 'V')
				g->map_cpy[y][x] = '0';
			x++;
		}
		y++;
	}
}
