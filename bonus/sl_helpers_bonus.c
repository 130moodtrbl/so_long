/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_helpers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:16 by speters           #+#    #+#             */
/*   Updated: 2025/03/28 15:13:45 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long_bonus.h"

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

int	ascii_count(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = n * (-1);
		size = 1;
	}
	if (n == 0)
	{
		size = 1;
	}
	else
	{
		while (n != 0)
		{
			n = n / 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*s;
	long	nb;
	int		neg;

	size = ascii_count((long) n);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	nb = (long)n;
	neg = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		s[0] = '-';
		neg = 1;
	}
	s[size] = '\0';
	while (size > (size_t) neg)
	{
		s[size - 1] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	return (s);
}

int	utils_strlen(const char *src)
{
	int	len;

	len = 0;
	if (!src)
		return (0);
	while (src[len])
	{
		len++;
	}
	return (len);
}
