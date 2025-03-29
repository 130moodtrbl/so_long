/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:01:25 by speters           #+#    #+#             */
/*   Updated: 2025/03/28 15:12:57 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

# define ESC 65307
# define W	119
# define S	115
# define A	97
# define D	100

# define C_REC "	[၊၊||၊] Ensure map is a rectangle. Out.\n"
# define C_WAL "	[၊၊||၊] Ensure borders are correct. Out.\n"
# define C_VI "	[၊၊||၊] Mayday. Unexpected elements detected. Out.\n\n"
# define RCP "	[၊၊||၊] Couldn't read the map. Out.\n"
# define C_DP "	[၊၊||၊] More than (1) player detected. Out.\n\n"
# define C_DE "	[၊၊||၊] More than (1) exit detected. Out.\n\n"
# define NO_VALID "	[၊၊||၊] Can't finish game. Check the configuration. Out.\n"
# define C_FP "🚀 Reaching Nova without a spaceship?\n	✩ Add a player.\n\n"
# define C_EX " 🚀 Has a blackhole absorbed Nova yet?\n	✩ Add an exit.\n\n"
# define C_CCO "🚀 Reaching Nova without fuel?\n ✩ Add (1+) collectible(s).\n\n"
# define NOMALLOC "✩ Malloc failed\n"

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*space_img;
	void	*player_img;
	void	*player_img_down;
	void	*player_img_up;
	void	*player_img_left;
	void	*player_img_right;
	void	*collec_img;
	void	*exit_img;
	char	**map;
	int		mapw;
	int		maph;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		move_count;
	int		items_count;
	int		items_collected;
	int		fff_exit_ok;
}	t_game;

void	load_images(t_game *game);
void	put_img_to_window(t_game *game, char elem, int x, int y);
void	init_game(t_game *game);
void	setup_game(t_game *game);
void	count_collectibles(t_game *game);
void	print_map(t_game *game);
void	find_player(t_game *game);
void	new_player_position(t_game *game, int new_x, int new_y);
void	change_directions(t_game *game, char direction);
void	move_player(t_game *game, int new_x, int new_y, char direction);
void	free_all(t_game *game);
void	free_map(char **map, int map_height);
void	exit_game(t_game *game, short int exit_status, char *exit_msg);
char	**make_map(int fd, int map_height);
char	**read_map(char *filename, int *map_height);
char	**read_check_map(char *filename, t_game *game);
int		keys(int keycode, t_game *game);
int		get_map_height(int fd);
int		check_move_ok(t_game *game, int new_x, int new_y);
int		close_window(t_game *game);

void	check_collec(t_game *game);
void	check_dup_player(t_game *game);
void	check_exit(t_game *game);
void	check_dup_exit(t_game *game);
void	check_rectangular(t_game *game);
void	check_walls(t_game *game);
void	check_valid_input(t_game *game);
void	check_one_line(t_game *game);
void	check_path_collec(t_game *game);
void	check_path_exit(t_game *game);
void	flood_fill_collectibles(char **map, int x, int y);
void	flood_fill_path(char **map, int x, int y);
void	validate_map(t_game *game);
int		check_extension(const char *filename, const char *extension);
int		check_args(int argc, char **argv);

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	**dup_map(t_game *game);
char	*ft_strrchr(const char *s, int c);
int		count_walls(t_game *game, int x, int y);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif