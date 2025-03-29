/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:16 by speters           #+#    #+#             */
/*   Updated: 2025/03/26 17:02:58 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

int	count_walls(t_game *game, int x, int y)
{
	int	walls;

	walls = 0;
	if (x > 0 && game->map[y][x - 1] == '1')
		walls++;
	if (x < game->mapw - 1 && game->map[y][x + 1] == '1')
		walls++;
	if (y > 0 && game->map[y - 1][x] == '1')
		walls++;
	if (y < game->maph - 1 && game->map[y + 1][x] == '1')
		walls++;
	return (walls);
}

char	**dup_map(t_game *game)
{
	int		y;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (game->maph + 1));
	if (!new_map)
		exit_game(game, EXIT_FAILURE, NOMALLOC);
	y = 0;
	while (y < game->maph)
	{
		new_map[y] = ft_strdup(game->map[y]);
		if (!new_map[y])
		{
			while (--y >= 0)
				free(new_map[y]);
			free(new_map);
			exit_game(game, EXIT_FAILURE, NOMALLOC);
		}
		y++;
	}
	new_map[y] = NULL;
	return (new_map);
}
