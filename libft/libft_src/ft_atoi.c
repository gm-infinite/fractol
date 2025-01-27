/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:00:38 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 09:31:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int		ret_i;
	int		neg;
	size_t	k;

	k = 0;
	neg = 1;
	while (str[k] == ' ' || ('\t' <= str[k] && str[k] <= '\r'))
		k++;
	if ((str[k] == '-' || str[k] == '+'))
	{
		if (str[k] == '-')
			neg = -1;
		k++;
	}
	ret_i = 0;
	while (ft_isdigit(str[k]))
	{
		ret_i = 10 * ret_i + (str[k] - '0');
		k++;
	}
	return (ret_i * neg);
}
