/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:27:00 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/16 19:23:13 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

void	error_list(int code)
{
	if (code == 1)
	{
		write(1, "Error\nExpected *.ber\n", 21);
		exit(0);
	}
	if (code == 2)
	{
		write(1, "Error\nWrong map format\n", 23);
		exit(0);
	}
}
