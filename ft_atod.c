/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:36:46 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/24 17:22:10 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static double ft_atod2(const char *str, size_t k)
{
	double	ret_f;
	double	ret_s;
	size_t i;

	ret_f = 0.0;
	ret_s = 0.0;
	i = 0;
	while (ft_isdigit(str[k]) && str[k] != '\0')
	{
		ret_f = 10 * ret_f + (str[k] - '0');
		k++;
	}
	if (str[k] == '.' || str[k] == ',')
		k++;
	while(ft_isdigit(str[k]) && str[k] != '\0')
		k++;
	while (ft_isdigit(str[--k]))
	{
		ret_s =  ret_s / 10 + ((double)(str[k] - '0') / 10);
	}
	return (ret_f + ret_s);
}

double ft_atod(const char *str)
{
	double		neg;
	size_t	k;

	k = 0;
	neg = 1.0;
	while (str[k] == ' ' || ('\t' <= str[k] && str[k] <= '\r'))
		k++;
	if ((str[k] == '-' || str[k] == '+'))
	{
		if (str[k] == '-')
			neg = -1.0;
		k++;
	}
	return (ft_atod2(str, k) * neg);
}
