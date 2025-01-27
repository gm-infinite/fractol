/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:58:18 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/24 17:47:49 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_julia_it(t_complex c, t_coordinate count, t_data *img, int color[])
{
	t_complex	z;
	int			i;

	i = 0;
	z.x = (ft_map(count.x, -2, +2, 0, WINDOW_WIDTH));
	z.y = (ft_map(count.y, +2, -2, 0, WINDOW_HEIGHT));
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

void julia(t_ft_window *wnd, char **argv)
{
	t_coordinate count;
	t_complex c;

	set_coordinate(&count, 0,0);
	c.x = ft_atod(argv[2]);
	c.y = ft_atod(argv[3]);
	while (count.x < WINDOW_WIDTH)
	{
		count.y = 0;
		while (count.y < WINDOW_HEIGHT)
		{
			ft_julia_it(c, count, &(wnd->img), wnd->color);
			count.y++;
		}
		count.x++;
	}
	mlx_put_image_to_window(wnd->mlx, wnd->mlx_window, wnd->img.img, 0, 0);
}
