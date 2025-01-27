/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trueprint_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:06:19 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:53 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_sizearrset(t_flags *flags, t_vavalue *material)
{
	if (flags->type_to_print == 1)
		return (ft_charsize((material->value_int)));
	else if (flags->type_to_print == 2)
		return (ft_stringsize((material->value_string)));
	else if (flags->type_to_print == 3)
		return (ft_deciintsize(material->value_int, flags));
	else if (flags->type_to_print == 4)
		return (ft_deciintsize(material->value_int, flags));
	else if (flags->type_to_print == 5)
		return (ft_unsintsize(material->value_unint, flags));
	else if (flags->type_to_print == 6)
		return (ft_hexasize(material->value_unint, flags));
	else if (flags->type_to_print == 7)
		return (ft_hexasize(material->value_unint, flags));
	else if (flags->type_to_print == 8)
		return (ft_pointersize(material->value_pointer));
	else if (flags->type_to_print == 9)
		return (ft_charsize('%'));
	return (0);
}

static void	ft_trueprintset3(t_flags *flags, t_trueprint *tp, \
t_vavalue *material)
{
	if ((flags->type_to_print == 3 || flags->type_to_print == 4) && \
	material->value_int < 0)
	{
		tp->sign = '-';
		tp->space_before_value--;
	}
	if (flags->after_or_before == 1)
	{
		tp->space_after_value = tp->space_before_value;
		tp->space_before_value = 0;
	}
	if (flags->zero_or_space == 1 && flags->dot_size == -1)
	{
		tp->zero_before_value += tp->space_before_value;
		tp->space_before_value = 0;
	}
}

static void	ft_trueprintset2(t_flags *flags, t_trueprint *tp, \
t_vavalue *material)
{
	if (flags->alternative == 1)
	{
		if (material->value_unint != 0 || \
		(flags->type_to_print == 8 && material->value_pointer != NULL))
		{
			tp->zerox = 1;
			tp->space_before_value -= 2;
		}
	}
	if (flags->space_plus > 0 && material->value_int >= 0)
	{
		if (flags->space_plus == 1)
			tp->sign = ' ';
		else if (flags->space_plus == 2)
			tp->sign = '+';
		if (tp->sign != '0')
			tp->space_before_value--;
	}
	ft_trueprintset3(flags, tp, material);
}

void	ft_trueprintset(t_flags *flags, va_list *args, \
t_trueprint *tp, t_vavalue *material)
{
	int		size;

	ft_vavaluereset(material);
	ft_vavalueset(material, args, flags);
	size = ft_sizearrset(flags, material);
	tp->space_before_value = flags->width - size;
	if (flags->dot_size >= 0)
	{
		tp->zero_before_value = flags->dot_size - size;
		if ((flags->type_to_print == 2 && flags->dot_size < size))
		{
			tp->space_before_value += (size - flags->dot_size);
			if (material->value_string == NULL)
				tp->space_before_value += flags->dot_size;
		}
		if ((flags->type_to_print >= 3 && flags->type_to_print <= 7) \
		&& flags->dot_size > size)
			tp->space_before_value -= tp->zero_before_value;
	}
	ft_trueprintset2(flags, tp, material);
}
