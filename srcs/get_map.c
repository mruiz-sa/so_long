/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:14:51 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/16 20:10:12 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<fcntl.h>

int	chars_map_checker(t_game *game)
{
	
}

int	map_checker(t_game *game)
{
	(game->map)->width = ft_strlen((game->map)->ber[0]);
	(game->map)->height = 0;
	while (game->map->ber[(game->map)->height])
		(game->map)->height++;
	if ((game->map)->height <= 2)
		return (1);
	if (chars_map_checker(game) == 1)
		return (1);
	return (0);
}

void	get_map(t_game *game, char *av)
{
	char	*line;
	char	*read_map;
	int		fd;

	game->map = calloc(1, sizeof(t_map));
	fd = open(av[1], O_RDONLY);
	read_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		read_map = ft_strjoin(read_map, line);
		free(line);
		line = get_next_line(fd);
	}
	(game->map)->ber = ft_split(read_map, '\n');
	if (!read_map || map_checker(game) == 1)
	{
		
	}
}
