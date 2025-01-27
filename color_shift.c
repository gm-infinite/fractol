/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:18:53 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/24 15:44:56 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void color_shift_left(int *color)
{
	int temp;
	int i;

	i = 0;
	temp = color[0];
	while(i < ITERATION - 1)
	{
		color[i] = color[i + 1];
		i++;
	}
	color[ITERATION - 1] = temp;
}

void color_shift_right(int *color)
{
	int temp;
	int i;

	i = 0;
	temp = color[ITERATION - 1];
	while(i < ITERATION - 1)
	{
		color[ITERATION - 1 - i ] = color[ITERATION - 2 - i];
		i++;
	}
	color[0] = temp;
}