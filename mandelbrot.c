/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:58:18 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/24 17:48:00 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double ft_map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

static void	ft_mandelbrot_it(t_coordinate count, t_data *img, int color[])
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	c.x = (ft_map(count.x, -2, +2, 0, WINDOW_WIDTH));
	c.y = (ft_map(count.y, +2, -2, 0, WINDOW_HEIGHT));
	z.x = 0.0;
	z.y = 0.0;
	while (i < ITERATION - 1)
	{
		z = add_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			ft_put_pixel(img, count.x, count.y, color[i]);
			return ;
		}
		i++;	
	}
	ft_put_pixel(img, count.x, count.y, FT_COLOR6);
}

void mandelbrot(t_ft_window *wnd)
{
	t_coordinate count;

	set_coordinate(&count, 0,0);
	while (count.x < WINDOW_WIDTH)
	{
		count.y = 0;
		while (count.y < WINDOW_HEIGHT)
		{
			ft_mandelbrot_it(count, &(wnd->img), wnd->color);
			count.y++;
		}
		count.x++;
	}
	mlx_put_image_to_window(wnd->mlx, wnd->mlx_window, wnd->img.img, 0, 0);
}
