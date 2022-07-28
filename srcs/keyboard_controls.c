/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:08:38 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/28 14:10:47 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_checker(t_game *game, int x, int y)
{
	if ((game->map)->ber[y][x] == '0' || (game->map)->ber[y][x] == 'C')
	{
		(game->map)->ber[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->moves_count++;
	}
	if ((game->map)->ber[y][x] == 'C')
		game->collectable_count--;
	if ((game->map)->ber[y][x] == 'E')
	{
		if (game->collectable_count != 0)
			return (0);
		printf("¡ALL \e[31m\e[1mPOKEBALLS\e[0m RECOLECTED, WELL DONE!\n");
		free_and_exit(game);
	}
	if ((game->map)->ber[y][x] == 'T')
	{
		printf("\e[31m\e[1mGAME OVER\e[0m\n");
		free_and_exit(game);
	}
	return (1);
}

int	a_d_keys(t_game *game, int key)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (key == 0)
	{
		if ((game->map)->ber[y][--x] == '1')
			return (0);
		if (move_checker(game, x, y) == 0)
			return (0);
		(game->map)->ber[y][x + 1] = '0';
		game->player = mlx_xpm_file_to_image(game->mlx, "img/le.xpm", &x, &y);
	}
	else if (key == 2)
	{
		if ((game->map)->ber[y][++x] == '1')
			return (0);
		if (move_checker(game, x, y) == 0)
			return (0);
		(game->map)->ber[y][x - 1] = '0';
		game->player = mlx_xpm_file_to_image(game->mlx, "img/ri.xpm", &x, &y);
	}
	return (1);
}

int	w_s_keys(t_game *game, int key)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (key == 13)
	{
		if ((game->map)->ber[--y][x] == '1')
			return (0);
		if (move_checker(game, x, y) == 0)
			return (0);
		(game->map)->ber[y + 1][x] = '0';
		game->player = mlx_xpm_file_to_image(game->mlx, "img/ba.xpm", &x, &y);
	}
	else if (key == 1)
	{
		if ((game->map)->ber[++y][x] == '1')
			return (0);
		if (move_checker(game, x, y) == 0)
			return (0);
		(game->map)->ber[y - 1][x] = '0';
		game->player = mlx_xpm_file_to_image(game->mlx, "img/fr.xpm", &x, &y);
	}
	return (1);
}

int	keyboard_controls(int key, t_game *game)
{
	int		move;

	if (key == 53)
		free_and_exit(game);
	if (key == 0)
		move = a_d_keys(game, key);
	if (key == 2)
		move = a_d_keys(game, key);
	if (key == 13)
		move = w_s_keys(game, key);
	if (key == 1)
		move = w_s_keys(game, key);
	if (move)
	{
		convert_images(game);
		convert_enemies(game, game->moves_count);
		printf("Steps: %d\n", game->moves_count);
	}
	return (1);
}
