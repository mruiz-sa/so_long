/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:16:49 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/14 12:41:06 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

void	so_long(char *av)
{
	t_game	game;
}

int	main(int ac, char **av)
{
	if (ac != 2)
		error_list(1);
	else
		so_long(av[1]);
	exit(0);
}
