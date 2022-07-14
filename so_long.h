/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:24:27 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/14 12:36:37 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include<stdlib.h>

typedef struct s_map{
	char	**ber;
	int		width;
	int		height;
}	t_map;

typedef struct s_game {
	void	*mlx;
	t_map	*map;
}	t_game;

#endif