/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putHEXAu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:12:44 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_puthexau2(unsigned int nb, t_flags *flags)
{
	char	*s;

	s = "0123456789ABCDEF";
	if (nb <= 15)
	{
		ft_vputchar(s[nb], flags);
	}
	else
	{
		ft_puthexau2(nb / 16, flags);
		ft_puthexau2(nb % 16, flags);
	}
}

void	ft_puthexau(unsigned int nb, t_flags *flags)
{
	if (nb == 0 && flags->dot_size == 0)
		return ;
	else
		ft_puthexau2(nb, flags);
}
