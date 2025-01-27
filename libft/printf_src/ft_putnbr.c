/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:12:44 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_putnbr2(long nb, t_flags *flags)
{
	if (nb <= 9)
	{
		ft_vputchar(nb + 48, flags);
	}
	else
	{
		ft_putnbr2(nb / 10, flags);
		ft_putnbr2(nb % 10, flags);
	}
}

void	ft_putnbr(long nb, t_flags *flags)
{
	if (nb < 0)
	{
		ft_putnbr2((-nb), flags);
	}
	else if (nb == 0 && flags->dot_size == 0)
		return ;
	else
		ft_putnbr2(nb, flags);
}
