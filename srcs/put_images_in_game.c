/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_in_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:02:37 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/25 13:02:06 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_collectables(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->collectables, width * 64, height * 64);
	game->collectable_count++;
}

void	put_images_in_game(t_game *game)
{
	int	x;
	int	y;

	game->player = mlx_xpm_file_to_image(game->mlx,
			"images/front_player.xpm", &x, &y);
	game->collectables = mlx_xpm_file_to_image(game->mlx,
			"images/collectables.xpm", &x, &y);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"images/floor.xpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"images/wall.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"images/exit.xpm", &x, &y);
}

void	convert_images(t_game *game)
{
	int	height;
	int	width;

	game->collectable_count = 0;
	height = 0;
	while (height < (game->map)->height)
	{
		width = 0;
		while ((game->map)->ber[height][width])
		{
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->floor, width * 64, height * 64);
			if ((game->map)->ber[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->wall, width * 64, height * 64);
			if ((game->map)->ber[height][width] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->exit, width * 64, height * 64);
			if ((game->map)->ber[height][width] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->player, width * 64, height * 64);
			if ((game->map)->ber[height][width] == 'C')
				put_collectables(game, height, width);
			width++;
		}
		height++;
	}
}
