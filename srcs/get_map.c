/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:14:51 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/17 22:07:51 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include<fcntl.h>
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

int	chars_map_checker(char *str, int row, int width)
{
	int		i;
	int		player_nbr;

	i = 0;
	player_nbr = 0;
	while (str[i])
	{
		if ((row == 0 || row == 2) && str[i] != '1')
			return (1);
		if (row == 1 && ((str[0] != '1') || (str[width - 1] != '1')))
			return (1);
		if (str[i] != '0' || str[i] != '1' || str[i] != 'C' || str[i] != 'E'
			|| str[i] != 'P' || str[i] != 'T')
			return (1);
		if (str[i] == 'P')
			player_nbr++;
		if (player_nbr == 2)
			return (1);
		i++;
	}
	if (i != width)
		return (1);
	return (0);
}

int	map_checker(t_game *game)
{
	int	row;

	(game->map)->width = ft_strlen((game->map)->ber[0]);
	(game->map)->height = 0;
	while ((game->map)->ber[(game->map)->height])
	{
		if ((game->map)->height == 0)
			row = 0;
		else if ((game->map)->ber[(game->map)->height + 1])
			row = 1;
		else
			row = 2;
		if (chars_map_checker((game->map)->ber[(game->map)->height], row,
				(game->map)->width) == 1)
			return (1);
		(game->map)->height++;
	}
	printf("%d\n", game->map->height);
	printf("%d\n", game->map->width);
	if ((game->map)->height <= 2)
		return (1);
	return (0);
}

void	get_map(t_game *game, char *av)
{
	char	*line;
	char	*read_map;
	int		fd;

	game->map = calloc(1, sizeof(t_map));
	fd = open(av, O_RDONLY);
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
		if (read_map)
			free_map(&game->map);
		free(read_map);
		error_list(2);
	}
	free(read_map);
}
