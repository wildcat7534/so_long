/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:22:50 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 06:25:34 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (ft_verif_file(argc, argv[1]))
		return (1);
	g.fd = open(argv[1], O_RDONLY);
	if (g.fd == -1)
	{
		write(2, "Error\nFile not found\n", 21);
		return (1);
	}
	g.line = get_next_line(g.fd);
	if (!g.line)
	{
		write(2, "Error\nFile is empty\n", 21);
		return (1);
	}
	ft_map_line(&g);
	if (ft_check_max(&g))
		return (ft_free_mlx(&g), 1);
	if (ft_make_windows(&g))
		return (0);
	ft_make_map(&g);
	return (0);
}
