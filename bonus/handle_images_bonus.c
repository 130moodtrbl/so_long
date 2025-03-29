/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:49:00 by speters           #+#    #+#             */
/*   Updated: 2025/03/28 15:13:15 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long_bonus.h"

void	load_images(t_game *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall.xpm", &game->mapw, &game->maph);
	game->space_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/space.xpm", &game->mapw, &game->maph);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/exit.xpm", &game->mapw, &game->maph);
	game->collec_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectible.xpm", &game->mapw, &game->maph);
	game->player_img_up = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_up.xpm", &game->mapw, &game->maph);
	game->player_img_down = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_down.xpm", &game->mapw, &game->maph);
	game->player_img_left = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_left.xpm", &game->mapw, &game->maph);
	game->player_img_right = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_right.xpm", &game->mapw, &game->maph);
	game->player_img = game->player_img_up;
}

void	put_img_to_window(t_game *game, char elem, int x, int y)
{
	if (elem == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img, x * 64, y * 64);
	else if (elem == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->space_img, x * 64, y * 64);
	else if (elem == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_img, x * 64, y * 64);
	else if (elem == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_img, x * 64, y * 64);
	else if (elem == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collec_img, x * 64, y * 64);
}

void	display_move(t_game *game)
{
	char	*str;
	char	*msg;

	mlx_clear_window(game->mlx, game->win);
	print_map(game);
	str = ft_itoa(game->move_count);
	msg = utils_strjoin("moves:", str);
	mlx_string_put(game->mlx, game->win, 74, 74, 0xFF647F, msg);
	free(str);
	free(msg);
}
