/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:13:57 by speters           #+#    #+#             */
/*   Updated: 2025/03/28 15:13:35 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long_bonus.h"

void	check_collec(t_game *game)
{
	int	c;
	int	x;
	int	y;

	c = 0;
	y = 0;
	while (y < game->maph)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				c++;
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
		x++;
		}
	y++;
	}
	if (c < 1)
		exit_game(game, EXIT_FAILURE, C_CCO);
}

void	check_dup_player(t_game *game)
{
	int	x;
	int	y;
	int	player_count;

	x = 0;
	y = 0;
	player_count = 0;
	while (y < game->maph)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				player_count++;
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
	y++;
	}
	if (player_count != 1)
		exit_game(game, EXIT_FAILURE, C_DP);
}

void	check_exit(t_game *game)
{
	int	exit_count;
	int	x;
	int	y;

	exit_count = 0;
	y = 0;
	x = 0;
	while (y < game->maph)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				exit_count++;
				game->exit_x = x;
				game->exit_y = y;
			}
		x++;
		}
	y++;
	}
	if (exit_count == 0)
		exit_game(game, EXIT_FAILURE, C_EX);
}

void	check_dup_exit(t_game *game)
{
	int	x;
	int	y;
	int	exit_count;

	x = 0;
	y = 0;
	exit_count = 0;
	while (y < game->maph)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				exit_count++;
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
	y++;
	}
	if (exit_count != 1)
		exit_game(game, EXIT_FAILURE, C_DE);
}
