/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:52:34 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/18 10:52:56 by mruiz-sa         ###   ########.fr       */
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