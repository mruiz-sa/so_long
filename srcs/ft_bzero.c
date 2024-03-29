/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:53:29 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/17 20:57:50 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*aux;

	aux = (char *)s;
	i = 0;
	while (i < n)
	{
		aux[i] = 0;
		i++;
	}
}
