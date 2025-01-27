/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:40:51 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/24 17:45:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractals(t_ft_window *wnd, char **argv)
{
	if(!ft_strncmp((wnd->argv)[1], "mandelbrot", 12))
		mandelbrot(wnd);
	else if (!ft_strncmp((wnd->argv)[1], "julia", 6))
		julia(wnd, argv);
		
}