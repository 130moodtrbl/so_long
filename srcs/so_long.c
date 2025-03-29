/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:13:05 by speters           #+#    #+#             */
/*   Updated: 2025/03/28 13:07:34 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (check_args(argc, argv))
		return (1);
	read_check_map(argv[1], &game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	count_collectibles(&game);
	game.win = mlx_new_window(game.mlx, game.mapw * 64, game.maph * 64, "Nova");
	if (!game.win)
	{
		free_map(game.map, game.maph);
		free(game.mlx);
		return (1);
	}
	setup_game(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, keys, &game);
	mlx_loop(game.mlx);
	return (0);
}
