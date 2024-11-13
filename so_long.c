/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:22:50 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 04:13:53 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (ft_verif_file(argc, argv[1]))
		return (1);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
	{
		ft_printf("Error\nFile not found\n");
		return (1);
	}
	game.line = get_next_line(game.fd);
	if (!game.line)
	{
		ft_printf("Error\nFile is empty\n");
		return (1);
	}
	ft_map_line(&game);
	if (ft_check_max(&game))
	{
		ft_free_mlx(&game);
		return (1);
	}
	if (ft_make_windows(&game))
		return (0);
	ft_printf("ft_make_windows\n");
	ft_printf("ft_make_map\n");
	ft_make_map(&game);
	return (0);
}
