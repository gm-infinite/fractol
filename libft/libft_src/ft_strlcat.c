/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:18:42 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 09:31:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	l;

	k = ft_strlen(dst);
	l = k;
	i = 0;
	if (l < dstsize - 1 && 0 < dstsize)
	{
		while (src [i] != '\0' && i < dstsize - l - 1)
		{
			dst[k] = src[i];
			i++;
			k++;
		}
		dst[k] = '\0';
	}
	if (l > dstsize)
		l = dstsize;
	return (ft_strlen(src) + l);
}
