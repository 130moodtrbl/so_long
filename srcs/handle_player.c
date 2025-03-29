/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:52:52 by speters           #+#    #+#             */
/*   Updated: 2025/03/29 11:19:58 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

void	find_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->maph)
	{
		x = 0;
		while (x < game->mapw)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
		x++;
		}
	y++;
	}
	exit_game(game, EXIT_FAILURE, C_FP);
}

int	check_move_ok(t_game *game, int new_x, int new_y)
{
	char	next_position;

	if (new_x < 0 || new_y < 0 || new_y >= game->maph || new_x >= game->mapw)
		return (0);
	next_position = game->map[new_y][new_x];
	if (next_position == '1')
		return (0);
	if (next_position == 'C')
	{
		game->items_collected++;
		game->map[new_y][new_x] = '0';
	}
	if (next_position == 'E' && game->items_collected < game->items_count)
	{
		ft_printf("✩ You need to collect all fuel first! ✩\n");
		return (0);
	}
	return (1);
}

void	new_player_position(t_game *game, int new_x, int new_y)
{
	char	next_position;

	next_position = game->map[new_y][new_x];
	if (game->map[game->player_y][game->player_x] != 'E')
		game->map[game->player_y][game->player_x] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->space_img,
		game->player_x * 64, game->player_y * 64);
	game->player_x = new_x;
	game->player_y = new_y;
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		game->player_x * 64, game->player_y * 64);
	if (next_position != 'E')
		game->map[new_y][new_x] = 'P';
}

void	change_directions(t_game *game, char direction)
{
	if (direction == 'u')
		game->player_img = game->player_img_up;
	else if (direction == 'd')
		game->player_img = game->player_img_down;
	else if (direction == 'l')
		game->player_img = game->player_img_left;
	else if (direction == 'r')
		game->player_img = game->player_img_right;
}

void	move_player(t_game *game, int new_x, int new_y, char direction)
{
	if (!check_move_ok(game, new_x, new_y))
		return ;
	new_player_position(game, new_x, new_y);
	game->move_count++;
	ft_printf("☆ moves: %d\r", game->move_count);
	if (game->map[new_y][new_x] == 'E' && game->items_collected ==
		game->items_count)
	{
		ft_printf("\n	🪐 Congratulations! You've reached Nova in %d moves!\n",
			game->move_count);
		exit_game(game, EXIT_SUCCESS, "	[၊၊||၊] Let's fly again? Over.\n\n");
	}
	change_directions(game, direction);
	print_map(game);
}
