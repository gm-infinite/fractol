/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:11:23 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_pointersize(void *value)
{
	unsigned long	k;
	int				len;

	if (value != NULL)
	{
		k = (unsigned long)value;
		len = 0;
		if (k == 0)
			len++;
		while (k != 0)
		{
			len++;
			k = k / 16;
		}
		return (len);
	}
	return (5);
}
