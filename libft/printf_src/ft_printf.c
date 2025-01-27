/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:37:40 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:53 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_printvalue(t_flags *flags, t_vavalue *material)
{
	if (flags->type_to_print == 1)
		ft_vputchar((material->value_int), flags);
	else if (flags->type_to_print == 2)
		ft_vputstr((material->value_string), flags);
	else if (flags->type_to_print == 3)
		ft_putnbr((material->value_int), flags);
	else if (flags->type_to_print == 4)
		ft_putnbr((material->value_int), flags);
	else if (flags->type_to_print == 5)
		ft_putunsnbr((material->value_unint), flags);
	else if (flags->type_to_print == 6)
		ft_puthexa((material->value_unint), flags);
	else if (flags->type_to_print == 7)
		ft_puthexau((material->value_unint), flags);
	else if (flags->type_to_print == 8)
		ft_putpointer((material->value_pointer), flags);
	else if (flags->type_to_print == 9)
		ft_vputchar('%', flags);
}

static void	ft_printtime2(t_flags *flags, t_trueprint *tp, t_vavalue *material)
{
	while (tp->zero_before_value > 0 && flags->type_to_print != 2)
	{
		ft_vputchar('0', flags);
		tp->zero_before_value--;
	}
	if (flags->dot_size >= 0 && flags->type_to_print == 2)
		ft_lenputstr(material->value_string, flags, flags->dot_size);
	else
		ft_printvalue(flags, material);
	while (tp->space_after_value > 0)
	{
		ft_vputchar(' ', flags);
		tp->space_after_value--;
	}
}

static void	ft_printtime(t_flags *flags, t_trueprint *tp, t_vavalue *material)
{
	while (tp->space_before_value > 0)
	{
		ft_vputchar(' ', flags);
		tp->space_before_value--;
	}
	if (tp->sign != '0')
		ft_vputchar(tp->sign, flags);
	if (tp->zerox > 0)
	{
		if (flags->type_to_print == 8)
			ft_vputstr("0x", flags);
		else if (material->value_unint != 0)
		{
			if (flags->type_to_print == 7)
				ft_vputstr("0X", flags);
			else
				ft_vputstr("0x", flags);
		}
	}
	ft_printtime2(flags, tp, material);
}

static int	percentfound(const char *s, t_flags *flags, va_list *args)
{
	int			skip;
	t_trueprint	trueprint;
	t_vavalue	material;

	ft_flagreset(flags);
	skip = ft_flagsset(s, flags);
	if (skip != -1)
	{
		ft_trueprintreset(&trueprint);
		ft_trueprintset(flags, args, &trueprint, &material);
		ft_printtime(flags, &trueprint, &material);
		return (skip);
	}
	ft_vputchar('%', flags);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_flags	flags;

	if (s == NULL)
		return (-1);
	va_start(args, s);
	flags.print_length = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s = s + percentfound(&s[1], &flags, &args);
		}
		else
			ft_vputchar(*s, &flags);
		s++;
	}
	va_end(args);
	return (flags.print_length);
}
