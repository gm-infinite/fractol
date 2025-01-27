/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:25:52 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 09:31:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_count_substr(char const *s, char c)
{
	size_t	count;
	size_t	at_deliminar;

	count = 0;
	at_deliminar = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!at_deliminar)
			{
				at_deliminar = 1;
				count++;
			}
		}
		else
			at_deliminar = 0;
		s++;
	}
	return (count);
}

static size_t	ft_nml(char	**split, const char *s, char c, size_t word_count)
{
	size_t	j;
	size_t	index;
	size_t	wlength;

	j = 0;
	index = 0;
	wlength = 0;
	while (s[j] && index < word_count)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			wlength++;
		}
		split[index] = (char *)malloc(sizeof(char) * (wlength + 1));
		if (!split[index])
			return (index);
		ft_strlcpy(split[index], &(s[j - wlength]), wlength + 1);
		wlength = 0;
		index++;
	}
	split[index] = NULL;
	return (index);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_count;
	size_t	check;

	if (!s)
		return (NULL);
	word_count = ft_count_substr(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	check = ft_nml(split, s, c, word_count);
	if (check != word_count)
	{
		while (0 < check)
		{
			free(split[check - 1]);
			check--;
		}
		free(split);
		return (NULL);
	}
	return (split);
}
