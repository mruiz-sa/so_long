/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:52:34 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/26 11:43:13 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include<stdlib.h>

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	while ((*map)->ber[i])
	{
		free((*map)->ber[i]);
		i++;
	}
	free((*map)->ber);
	free(*map);
}

void	free_and_exit(t_game *game)
{
	int	i;

	i = 0;
	if (game->mlx_window)
		mlx_destroy_window(game->mlx, game->mlx_window);
	free(game->mlx);
	while ((game->map)->ber[i])
	{
		free((game->map)->ber[i]);
		i++;
	}
	free((game->map)->ber);
	free(game->map);
	exit(0);
}
