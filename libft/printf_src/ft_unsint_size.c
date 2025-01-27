/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:10:20 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_unsintsize(unsigned int value, t_flags *flags)
{
	int	len;

	len = 0;
	if (value == 0 && flags->dot_size == 0)
		return (0);
	if (value == 0)
		len++;
	while (value != 0)
	{
		len++;
		value = value / 10;
	}
	return (len);
}
