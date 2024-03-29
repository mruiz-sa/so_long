/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:14:51 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/29 12:08:07 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include<fcntl.h>
#include<stdlib.h>

int	wall_map_checker(char *str, int row, int width)
{
	int		i;
	int		player_nbr;

	i = 0;
	player_nbr = 0;
	while (str[i])
	{
		if ((row == 0 || row == 2) && str[i] != '1' && i < (width))
			return (1);
		if (row == 1 && ((str[0] != '1') || (str[width - 1] != '1')))
			return (1);
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C' && str[i] != 'E'
			&& str[i] != 'P' && str[i] != '\n')
			return (1);
		i++;
	}
	if (i != width + 1)
		return (1);
	return (0);
}

int	map_checker(t_game *game)
{
	int	row;
	int	i;

	i = 0;
	(game->map)->height = 0;
	(game->map)->width = ft_strlen((game->map)->ber[0]) - 1;
	while ((game->map)->ber[(game->map)->height])
	{
		if ((game->map)->height == 0)
			row = 0;
		else if ((game->map)->ber[(game->map)->height + 1])
			row = 1;
		else
			row = 2;
		if (wall_map_checker((game->map)->ber[(game->map)->height], row,
				(game->map)->width) == 1)
			return (1);
		(game->map)->height++;
	}
	if ((game->map)->height <= 2 || (game->map)->height == (game->map)->width)
		return (1);
	return (0);
}

int	char_checker(char *str)
{
	int	i;
	int	p;
	int	c;
	int	e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			c++;
		if (str[i] == 'P')
			p++;
		if (str[i] == 'E')
			e++;
		i++;
	}
	if (p != 1)
		return (1);
	if (c < 1 || e < 1)
		return (1);
	return (0);
}

char	*modify_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	map[i] = '\n';
	map[i + 1] = '\0';
	return (map);
}

void	get_map(t_game *game, char *av)
{
	t_reading_map	read;

	game->map = ft_calloc(1, sizeof(t_map));
	read.fd = open(av, O_RDONLY);
	if (read.fd == -1)
		error_list(3);
	read.read_map = 0;
	read.line = get_next_line(read.fd);
	while (read.line)
	{
		read.read_map = ft_strjoin(read.read_map, read.line);
		free(read.line);
		read.line = get_next_line(read.fd);
	}
	free(read.line);
	read.read_map = modify_map(read.read_map);
	(game->map)->ber = ft_split(read.read_map, '\n');
	if (!read.read_map || map_checker(game) || char_checker(read.read_map))
	{
		if (read.read_map)
			free_map(&game->map);
		free(read.read_map);
		error_list(2);
	}
	free(read.read_map);
}
