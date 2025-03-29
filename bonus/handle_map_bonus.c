/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:49:41 by speters           #+#    #+#             */
/*   Updated: 2025/03/28 15:13:27 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long_bonus.h"

int	get_map_height(int fd)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	return (height);
}

char	**make_map(int fd, int map_height)
{
	char	**map;
	char	*line;
	size_t	len;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (map_height + 1));
	if (!map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**read_map(char *filename, int *map_height)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	*map_height = get_map_height(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = make_map(fd, *map_height);
	close(fd);
	return (map);
}

char	**read_check_map(char *filename, t_game *game)
{
	game->map = read_map(filename, &(game->maph));
	if (!game->map)
	{
		exit_game(game, EXIT_FAILURE, RCP);
	}
	game->mapw = ft_strlen(game->map[0]);
	check_walls(game);
	check_rectangular(game);
	find_player(game);
	check_exit(game);
	check_dup_player(game);
	check_dup_exit(game);
	check_valid_input(game);
	check_collec(game);
	check_one_line(game);
	validate_map(game);
	return (game->map);
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			put_img_to_window(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
