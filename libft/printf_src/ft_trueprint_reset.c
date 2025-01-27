/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trueprint_reset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:10:40 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:53 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_trueprintreset(t_trueprint *tp)
{
	tp->space_before_value = 0;
	tp->sign = '0';
	tp->zero_before_value = 0;
	tp->zerox = 0;
	tp->space_after_value = 0;
}
