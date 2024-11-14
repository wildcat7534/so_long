/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso_key2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 05:42:07 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 05:50:17 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mv_left(t_game *g)
{
	g->nb_moves++;
	ft_printf("nb_moves = %d\n", g->nb_moves);
	mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.floor, g->p.x
		* TL, g->p.y * TL);
	g->p.x--;
	if (g->map.map[g->p.y][g->p.x] == 'E')
		game_over(g);
	else
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.player,
			g->p.x * TL, g->p.y * TL);
}

void	mv_right(t_game *g)
{
	g->nb_moves++;
	ft_printf("nb_moves = %d\n", g->nb_moves);
	mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.floor, g->p.x
		* TL, g->p.y * TL);
	g->p.x++;
	if (g->map.map[g->p.y][g->p.x] == 'E')
		game_over(g);
	else
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.player,
			g->p.x * TL, g->p.y * TL);
}

void	mv_up(t_game *g)
{
	g->nb_moves++;
	ft_printf("nb_moves = %d\n", g->nb_moves);
	mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.floor, g->p.x
		* TL, g->p.y * TL);
	g->p.y--;
	if (g->map.map[g->p.y][g->p.x] == 'E')
		game_over(g);
	else
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.player,
			g->p.x * TL, g->p.y * TL);
}

void	mv_down(t_game *g)
{
	g->nb_moves++;
	ft_printf("nb_moves = %d\n", g->nb_moves);
	mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.floor, g->p.x
		* TL, g->p.y * TL);
	g->p.y++;
	if (g->map.map[g->p.y][g->p.x] == 'E')
		game_over(g);
	else
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.player,
			g->p.x * TL, g->p.y * TL);
}
