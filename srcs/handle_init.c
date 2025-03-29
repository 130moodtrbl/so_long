/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:05:22 by speters           #+#    #+#             */
/*   Updated: 2025/03/26 17:08:42 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->wall_img = NULL;
	game->space_img = NULL;
	game->exit_img = NULL;
	game->collec_img = NULL;
	game->player_img_down = NULL;
	game->player_img_left = NULL;
	game->player_img_right = NULL;
	game->player_img_up = NULL;
	game->map = NULL;
	game->mapw = 0;
	game->maph = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->move_count = 0;
	game->items_count = 0;
	game->items_collected = 0;
	game->fff_exit_ok = 0;
}

void	setup_game(t_game *game)
{
	load_images(game);
	print_map(game);
}

void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	game->items_count = 0;
	game->items_collected = 0;
	y = 0;
	while (y < game->maph)
	{
		x = 0;
		while (x < game->mapw)
		{
			if (game->map[y][x] == 'C')
				game->items_count++;
		x++;
		}
	y++;
	}
}

int	keys(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == W)
		move_player(game, game->player_x, game->player_y - 1, 'u');
	else if (keycode == S)
		move_player(game, game->player_x, game->player_y + 1, 'd');
	else if (keycode == A)
		move_player(game, game->player_x - 1, game->player_y, 'l');
	else if (keycode == D)
		move_player(game, game->player_x + 1, game->player_y, 'r');
	else
		return (0);
	return (0);
}
