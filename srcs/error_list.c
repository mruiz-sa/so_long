/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:27:00 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/07/26 11:53:54 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

void	error_list(int code)
{
	if (code == 1)
	{
		printf("Error\nExpected *.ber\n");
		exit(0);
	}
	if (code == 2)
	{
		printf("Error\nWrong map format\n");
		exit(0);
	}
	if (code == 3)
	{
		printf("Error\nFile not found\n");
		exit(0);
	}
	if (code == 4)
	{
		printf("Error\nWrong file format, expected: *.ber\n");
		exit(0);
	}
}
