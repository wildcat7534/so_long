/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:31:49 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 21:49:04 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_img(t_game *game)
{
	int	t;

	ft_printf("ft_init_img\n");
	t = 55;
	game->img.wall = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"img/mur.xpm", &t, &t);
	game->img.floor = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"img/sol.xpm", &t, &t);
	game->img.player = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"img/py.xpm", &t, &t);
	game->img.item = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"img/fille.xpm", &t, &t);
	game->img.exit = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"img/chato.xpm", &t, &t);
	game->img.exit_no = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"img/finNo.xpm", &t, &t);
	if (!game->img.wall || !game->img.floor || !game->img.player
		|| !game->img.item || !game->img.exit || !game->img.exit_no)
	{
		ft_printf("Error\n* fail : mlx_xpm_file_to_image\n");
		ft_free_mlx(game);
		exit(1);
	}
	ft_printf("\n OK : mlx_xpm_file_to_image\n");
}
