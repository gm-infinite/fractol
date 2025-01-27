/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:31:13 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 09:31:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*ans;

	size = ft_strlen(s);
	if (start >= size)
	{
		ans = (char *)malloc(sizeof(char));
		if (!ans)
			return (NULL);
		ans[0] = '\0';
	}
	else
	{
		size = size - start;
		if (len < size)
			size = len;
		ans = (char *)malloc(sizeof(char) * (size + 1));
		if (!ans)
			return (NULL);
		ft_strlcpy(ans, s + start, size + 1);
	}
	return (ans);
}
