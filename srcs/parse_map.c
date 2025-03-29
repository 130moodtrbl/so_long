/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:15:07 by speters           #+#    #+#             */
/*   Updated: 2025/03/27 17:40:24 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long.h"

void	check_rectangular(t_game *game)
{
	int	i;
	int	width;

	i = 1;
	width = ft_strlen(game->map[0]);
	while (i < game->maph)
	{
		if ((int)ft_strlen(game->map[i]) != width || width == game->maph)
			exit_game(game, EXIT_FAILURE, C_REC);
		i++;
	}
}

void	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->mapw)
	{
		if (game->map[0][x] != '1' || game->map[game->maph - 1][x] != '1')
			exit_game(game, EXIT_FAILURE, C_WAL);
		x++;
	}
	while (y < game->maph)
	{
		if (game->map[y][0] != '1' || game->map[y][game->mapw - 1] != '1')
			exit_game(game, EXIT_FAILURE, C_WAL);
	y++;
	}
}

void	check_valid_input(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->maph)
	{
		x = 0;
		while (game->map[y][x])
		{
			c = game->map[y][x];
			if (c != 'P' && c != '1' && c != 'E' && c != 'C' && c != '0')
				exit_game(game, EXIT_FAILURE, C_VI);
			x++;
		}
		y++;
	}
}

void	check_one_line(t_game *game)
{
	int	x_p;
	int	x_c;
	int	x_e;
	int	x;

	if (game->maph != 3)
		return ;
	x_p = -1;
	x_c = -1;
	x_e = -1;
	x = 0;
	while (x < game->mapw)
	{
		if (game->map[1][x] == 'P')
			x_p = x;
		else if (game->map[1][x] == 'C')
			x_c = x;
		else if (game->map[1][x] == 'E')
			x_e = x;
		x++;
	}
	if (x_p != -1 && x_c != -1 && x_e != -1)
		if ((x_p < x_e && x_e < x_c) || (x_c < x_e && x_e < x_p))
			exit_game(game, EXIT_FAILURE, NO_VALID);
}
