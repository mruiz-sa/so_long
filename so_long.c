/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:16:49 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/16 17:19:35 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"
#include "minilibx/mlx.h"

void	so_long(char *av)
{
	t_game	game;

	get_map(&game, av);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, 
		game.map->width * 64, game.map->height * 64, "so_long");
}

int	main(int ac, char **av)
{
	if (ac != 2)
		error_list(1);
	else
		so_long(av[1]);
	exit(0);
}
