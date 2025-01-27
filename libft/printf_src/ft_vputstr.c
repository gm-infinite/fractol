/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:00:59 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_vputstr(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_vputstr("(null)", flags);
	}
	else
	{
		while (s[i])
		{
			ft_vputchar(s[i], flags);
			i++;
		}
	}
}
