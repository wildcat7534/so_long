/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:31:49 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 06:25:34 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_img(t_game *g)
{
	int	t;

	t = 55;
	g->img.wall = mlx_xpm_file_to_image(g->d.mlx_ptr,
			"./sources_so_long/img/mur.xpm", &t, &t);
	g->img.floor = mlx_xpm_file_to_image(g->d.mlx_ptr,
			"./sources_so_long/img/sol.xpm", &t, &t);
	g->img.player = mlx_xpm_file_to_image(g->d.mlx_ptr,
			"./sources_so_long/img/py.xpm", &t, &t);
	g->img.item = mlx_xpm_file_to_image(g->d.mlx_ptr,
			"./sources_so_long/img/fille.xpm", &t, &t);
	g->img.exit = mlx_xpm_file_to_image(g->d.mlx_ptr,
			"./sources_so_long/img/chato.xpm", &t, &t);
	g->img.exit_no = mlx_xpm_file_to_image(g->d.mlx_ptr,
			"./sources_so_long/img/finNo.xpm", &t, &t);
	if (!g->img.wall || !g->img.floor || !g->img.player
		|| !g->img.item || !g->img.exit || !g->img.exit_no)
	{
		write(2, "Error\n* fail : mlx_xpm_file_to_image\n", 37);
		ft_free_mlx(g);
		exit(1);
	}
}
