/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:16:49 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/29 10:53:53 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"
#include "minilibx/mlx.h"
#include<stdio.h>

void	extension_checker(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
		error_list(4);
}

void	so_long(char *av)
{
	t_game	game;

	game.mlx = mlx_init();
	get_map(&game, av);
	game.mlx_window = mlx_new_window(game.mlx,
			game.map->width * 64, game.map->height * 64, "so_long");
	game.moves_count = 0;
	put_images_in_game(&game);
	convert_images(&game);
	mlx_key_hook(game.mlx_window, keyboard_controls, &game);
	mlx_hook(game.mlx_window, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		error_list(1);
	else
	{
		extension_checker(av[1]);
		so_long(av[1]);
	}
	exit(0);
}
