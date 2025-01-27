/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vavalue_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:14:52 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:53 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_vavalueset(t_vavalue *vavalue, va_list *args, t_flags *flags)
{
	if (flags->type_to_print == 1 || flags->type_to_print == 3 \
	|| flags->type_to_print == 4)
	{
		vavalue->value_int = va_arg(*args, int);
	}
	else if (flags->type_to_print >= 5 && flags->type_to_print <= 7)
	{
		vavalue->value_unint = va_arg(*args, unsigned int);
	}
	else if (flags->type_to_print == 2)
	{
		vavalue->value_string = va_arg(*args, char *);
	}
	else if (flags->type_to_print == 8)
	{
		vavalue->value_pointer = va_arg(*args, void *);
	}
}
