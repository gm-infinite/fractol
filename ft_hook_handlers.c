/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:40:36 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/24 17:44:48 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_handler(int keycode, t_ft_window *wnd)
{
	if (keycode == XK_k)
	{
		color_shift_right(wnd->color);
		fractals(wnd, wnd->argv);
	}
	else if (keycode == XK_j)
	{
		color_shift_left(wnd->color);
		fractals(wnd, wnd->argv);
	}
	else if (keycode == XK_Escape)
	{
		mlx_destroy_image(wnd->mlx, (wnd->img.img));
		mlx_destroy_window(wnd->mlx, wnd->mlx_window);
		mlx_destroy_display(wnd->mlx);
		exit (0);
	}
	return (0);
}
