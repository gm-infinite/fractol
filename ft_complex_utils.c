/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:08:24 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/23 16:40:55 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void set_complex(t_complex *a, double x, double y)
{
	a->x = x;
	a->y = y;
}

t_complex square_complex(t_complex a)
{
	t_complex ret;
	
	ret.x = a.x * a.x - a.y * a.y;
	ret.y = 2 * a.x * a.y;
	return (ret);
}

t_complex add_complex(t_complex a, t_complex b)
{
	t_complex ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

