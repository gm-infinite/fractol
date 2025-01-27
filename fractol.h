/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:42:58 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/24 17:48:14 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
#include <stdio.h>

# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 1500
# define ITERATION 50
# define FT_COLOR1	0xcc0000
# define FT_COLOR2	0xcccc00
# define FT_COLOR3	0x00cc00
# define FT_COLOR4	0x0000cc
# define FT_COLOR5	0xcc00cc
# define FT_COLOR6	0x000000

typedef struct	s_trgb {
	unsigned char t;
	unsigned char r;
	unsigned char g;
	unsigned char b;
}		t_trgb;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_ft_window {
	t_data img;
	void *mlx;
	void *mlx_window;
	int color[ITERATION];
	char **argv;
}		t_ft_window;

typedef struct	s_coordinate {
	int x;
	int y;
}			t_coordinate;

typedef struct	s_complex {
	double x;
	double y;
}			t_complex;

void set_coordinate(t_coordinate *vec, int nx, int ny);
void mandelbrot(t_ft_window *wnd);
void ft_put_pixel(t_data *data, int x, int y, int color);
void set_complex(t_complex *a, double x, double y);
t_complex square_complex(t_complex a);
t_complex add_complex(t_complex a, t_complex b);
void set_ft_window(t_ft_window *wnd, char **argv);
double ft_map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
void set_color(int *color);
void color_shift_left(int *color);
void color_shift_right(int *color);
int key_handler(int keycode, t_ft_window *wnd);
void fractals(t_ft_window *wnd, char **argv);
double ft_atod(const char *str);
void julia(t_ft_window *wnd, char **argv);

#endif