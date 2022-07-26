/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:24:27 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/26 12:42:54 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "get_next_line.h"
# include<stdlib.h>

# define ESC 53

typedef struct s_reading_map{
	char	*line;
	char	*read_map;
	int		fd;
}	t_reading_map;

typedef struct s_map{
	char	**ber;
	int		width;
	int		height;
	int		row;
}	t_map;

typedef struct s_game {
	void	*mlx;
	void	*mlx_window;
	t_map	*map;
	void	*player;
	void	*collectables;
	void	*collectable_count;
	void	*floor;
	void	*wall;
	void	*exit;
	int		player_x;
	int		player_y;
	int		moves_count;

}	t_game;

void	get_map(t_game *game, char *av);
void	error_list(int code);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_map(t_map **map);
void	free_and_exit(t_game *game);
void	convert_images(t_game *game);
void	put_images_in_game(t_game *game);
int		keyboard_controls(int key, t_game *game);

#endif