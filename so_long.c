/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:16:49 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/13 12:16:56 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;

	i = 480;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (i <= 1440)
	{
		my_mlx_pixel_put(&img, i, 270, 0x00FF0000);
		i++;
	}
	i = 270;
	while (i <= 810)
	{
		my_mlx_pixel_put(&img, 480, i, 0x0000FF00);
		i++;
	}
	i = 480;
	while (i <= 1440)
	{
		my_mlx_pixel_put(&img, i, 810, 0x000000FF);
		i++;
	}
	i = 270;
	while (i <= 810)
	{
		my_mlx_pixel_put(&img, 1440, i, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 5, 4);
	mlx_loop(mlx);
}
