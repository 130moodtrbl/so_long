/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:47:18 by speters           #+#    #+#             */
/*   Updated: 2025/03/28 15:13:33 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long_bonus.h"

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->wall_img != NULL)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img != NULL)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->space_img != NULL)
		mlx_destroy_image(game->mlx, game->space_img);
	if (game->collec_img != NULL)
		mlx_destroy_image(game->mlx, game->collec_img);
	if (game->player_img_up != NULL)
		mlx_destroy_image(game->mlx, game->player_img_up);
	if (game->player_img_down != NULL)
		mlx_destroy_image(game->mlx, game->player_img_down);
	if (game->player_img_left != NULL)
		mlx_destroy_image(game->mlx, game->player_img_left);
	if (game->player_img_right != NULL)
		mlx_destroy_image(game->mlx, game->player_img_right);
	if (game->map != NULL)
		free_map(game->map, game->maph);
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx != NULL)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_map(char **map, int map_height)
{
	int	i;

	(void)map_height;
	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

int	close_window(t_game *game)
{
	ft_printf("\n[၊၊||၊] This is Hyperstellar base. Mission cancelled. Out.\n\n");
	free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	exit_game(t_game *game, short int exit_status, char *exit_msg)
{
	if (exit_status == EXIT_FAILURE && exit_msg)
	{
		ft_printf("Error\n");
		ft_printf("%s\n", exit_msg);
	}
	else if (exit_status == EXIT_SUCCESS && exit_msg)
		ft_printf("%s", exit_msg);
	if (game)
		free_all(game);
	exit(exit_status);
}
