/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:12:44 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_puthexa2(unsigned int nb, t_flags *flags)
{
	char	*s;

	s = "0123456789abcdef";
	if (nb <= 15)
	{
		ft_vputchar(s[nb], flags);
	}
	else
	{
		ft_puthexa2(nb / 16, flags);
		ft_puthexa2(nb % 16, flags);
	}
}

void	ft_puthexa(unsigned int nb, t_flags *flags)
{
	if (nb == 0 && flags->dot_size == 0 && flags->type_to_print != 8)
		return ;
	else
		ft_puthexa2(nb, flags);
}
