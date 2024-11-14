/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:28:44 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 05:50:17 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	perso_keyhook(int keysym, t_game *g)
{
	if (keysym == XK_Escape)
	{
		ft_free_mlx(g);
		exit(0);
	}
	if (keysym == XK_w || keysym == XK_Up)
		ft_move_up(g);
	if (keysym == XK_s || keysym == XK_Down)
		ft_move_down(g);
	if (keysym == XK_a || keysym == XK_Left)
		ft_move_left(g);
	if (keysym == XK_d || keysym == XK_Right)
		ft_move_right(g);
	return (0);
}

void	ft_move_left(t_game *g)
{
	if (g->map.map[g->p.y][g->p.x - 1] == '1')
		return ;
	else if (g->map.map[g->p.y][g->p.x] == 'E')
	{
		g->nb_moves++;
		ft_printf("nb_moves = %d\n", g->nb_moves);
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.exit, g->p.x
			* TL, g->p.y * TL);
		g->p.x--;
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.player,
			g->p.x * TL, g->p.y * TL);
	}
	else
		mv_left(g);
	if (g->map.map[g->p.y][g->p.x] == 'C')
	{
		g->count_collectibles++;
		g->map.map[g->p.y][g->p.x] = '0';
	}
}

void	ft_move_right(t_game *g)
{
	if (g->map.map[g->p.y][g->p.x + 1] == '1')
		return ;
	else if (g->map.map[g->p.y][g->p.x] == 'E')
	{
		g->nb_moves++;
		ft_printf("nb_moves = %d\n", g->nb_moves);
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.exit, g->p.x
			* TL, g->p.y * TL);
		g->p.x++;
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.player,
			g->p.x * TL, g->p.y * TL);
	}
	else
		mv_right(g);
	if (g->map.map[g->p.y][g->p.x] == 'C')
	{
		g->count_collectibles++;
		g->map.map[g->p.y][g->p.x] = '0';
	}
}

void	ft_move_up(t_game *g)
{
	if (g->map.map[g->p.y - 1][g->p.x] == '1')
		return ;
	else if (g->map.map[g->p.y][g->p.x] == 'E')
	{
		g->nb_moves++;
		ft_printf("nb_moves = %d\n", g->nb_moves);
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.exit, g->p.x
			* TL, g->p.y * TL);
		g->p.y--;
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.player,
			g->p.x * TL, g->p.y * TL);
	}
	else
		mv_up(g);
	if (g->map.map[g->p.y][g->p.x] == 'C')
	{
		g->count_collectibles++;
		g->map.map[g->p.y][g->p.x] = '0';
	}
}

void	ft_move_down(t_game *g)
{
	if (g->map.map[g->p.y + 1][g->p.x] == '1')
		return ;
	else if (g->map.map[g->p.y][g->p.x] == 'E')
	{
		g->nb_moves++;
		ft_printf("nb_moves = %d\n", g->nb_moves);
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.exit, g->p.x
			* TL, g->p.y * TL);
		g->p.y++;
		mlx_put_image_to_window(g->d.mlx_ptr, g->d.win_ptr, g->img.player,
			g->p.x * TL, g->p.y * TL);
	}
	else
		mv_down(g);
	if (g->map.map[g->p.y][g->p.x] == 'C')
	{
		g->count_collectibles++;
		g->map.map[g->p.y][g->p.x] = '0';
	}
}
