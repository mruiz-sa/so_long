/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:24:27 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/17 21:36:37 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "get_next_line.h"
# include<stdlib.h>

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
}	t_game;

void	get_map(t_game *game, char *av);
void	error_list(int code);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif