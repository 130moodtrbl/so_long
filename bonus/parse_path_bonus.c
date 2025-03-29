/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:18:27 by speters           #+#    #+#             */
/*   Updated: 2025/03/28 15:13:41 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long_bonus.h"

void	flood_fill_collectibles(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x]
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == '0')
		map[y][x] = 'V';
	flood_fill_collectibles(map, x - 1, y);
	flood_fill_collectibles(map, x + 1, y);
	flood_fill_collectibles(map, x, y - 1);
	flood_fill_collectibles(map, x, y + 1);
}

void	flood_fill_path(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x]
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E'
		|| map[y][x] == '0' || map[y][x] == 'P')
		map[y][x] = 'V';
	flood_fill_path(map, x - 1, y);
	flood_fill_path(map, x + 1, y);
	flood_fill_path(map, x, y - 1);
	flood_fill_path(map, x, y + 1);
}

void	check_path_collec(t_game *game)
{
	char	**mapcopy;
	int		x;
	int		y;

	mapcopy = dup_map(game);
	flood_fill_collectibles(mapcopy, game->player_x, game->player_y);
	y = 0;
	while (y < game->maph)
	{
		x = 0;
		while (mapcopy[y][x])
		{
			if (mapcopy[y][x] == 'C')
			{
				free_map(mapcopy, game->maph);
				exit_game(game, EXIT_FAILURE, NO_VALID);
			}
			x++;
		}
		y++;
	}
	free_map(mapcopy, game->maph);
}

void	check_path_exit(t_game *game)
{
	char	**mapcopy;
	int		x;
	int		y;

	mapcopy = dup_map(game);
	flood_fill_path(mapcopy, game->player_x, game->player_y);
	y = 0;
	while (y < game->maph)
	{
		x = 0;
		while (mapcopy[y][x])
		{
			if (mapcopy[y][x] == 'E')
			{
				free_map(mapcopy, game->maph);
				exit_game(game, EXIT_FAILURE, NO_VALID);
			}
			x++;
		}
		y++;
	}
	free_map(mapcopy, game->maph);
}

void	validate_map(t_game *game)
{
	check_path_collec(game);
	check_path_exit(game);
}
