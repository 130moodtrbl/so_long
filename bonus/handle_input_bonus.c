/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:45:51 by speters           #+#    #+#             */
/*   Updated: 2025/03/28 15:13:25 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/so_long_bonus.h"

int	check_extension(const char *filename, const char *extension)
{
	const char	*begext;

	begext = ft_strrchr(filename, '.');
	if (!begext || begext == filename)
		return (0);
	if (ft_strncmp(begext, extension, 4))
		return (1);
	else
		return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error\n	✩ Missing arguments! → [map_lvl.ber]\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_printf("Error\n	✩ Too many arguments! → [map_lvl.ber]\n");
		return (1);
	}
	if (check_extension(argv[1], ".ber") == 1)
	{
		ft_printf("Error\n	✩ Extension has to be .ber! → [map_lvl.ber]\n");
		return (1);
	}
	if (argv[1][0] == '.' || argv[1][5] == '.')
	{
		ft_printf("Error\n	✩ No hidden file allowed! → [map_lvl.ber]\n");
		return (1);
	}
	return (0);
}
