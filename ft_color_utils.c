/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:53:22 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/24 16:09:20 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_trgb int_to_trgb(int color)
{
	t_trgb temp;

	temp.t = ((color >> 24) & 0xFF);
	temp.r = ((color >> 16) & 0xFF);
	temp.g = ((color >> 8) & 0xFF);
	temp.b = (color  & 0xFF);
	return (temp);
}

static int trgb_to_int(t_trgb color)
{
	return (color.t << 24 | color.r << 16 | color.g << 8 | color.b);
}

static t_trgb avrg_trgb(t_trgb color1, t_trgb color2, double ratio)
{
	t_trgb temp;
	temp.t = 255;
	temp.r = (unsigned char)round(color1.r * (1 - ratio) + color2.r * ratio);
	temp.g = (unsigned char)round(color1.g * (1 - ratio) + color2.g * ratio);
	temp.b = (unsigned char)round(color1.b * (1 - ratio) + color2.b * ratio);
	return (temp);
}

static int ft_map_trgb(int i)
{
	double s;

	s = ft_map(i, 0, 5, 0, ITERATION - 1);
	if (s < 1)
		return (trgb_to_int(avrg_trgb(int_to_trgb(FT_COLOR1), int_to_trgb(FT_COLOR2), sqrt(s))));
	else if (s < 2)
		return (trgb_to_int(avrg_trgb(int_to_trgb(FT_COLOR2), int_to_trgb(FT_COLOR3), sqrt((s - 1)))));
	else if (s < 3)
		return (trgb_to_int(avrg_trgb(int_to_trgb(FT_COLOR3), int_to_trgb(FT_COLOR4), sqrt((s - 2)))));
	else if (s < 4)
		return (trgb_to_int(avrg_trgb(int_to_trgb(FT_COLOR4), int_to_trgb(FT_COLOR5), sqrt((s - 3)))));
	else 
		return (trgb_to_int(avrg_trgb(int_to_trgb(FT_COLOR5), int_to_trgb(FT_COLOR1), sqrt((s - 4)))));
	return (0);
}

void set_color(int *color)
{
	int i;

	i = 0;
	while (i < ITERATION)
	{
		color[i] = ft_map_trgb(i);
		i++;
	}
}