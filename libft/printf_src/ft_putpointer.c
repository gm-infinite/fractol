/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:12:44 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_putpointer2(unsigned long k, t_flags *flags)
{
	char			*s;

	s = "0123456789abcdef";
	if (k <= 15)
	{
		ft_vputchar(s[k], flags);
	}
	else
	{
		ft_putpointer2(k / 16, flags);
		ft_putpointer2(k % 16, flags);
	}
}

void	ft_putpointer(void *nb, t_flags *flags)
{
	if (nb == NULL)
		ft_vputstr("(nil)", flags);
	else
		ft_putpointer2((unsigned long)nb, flags);
}
