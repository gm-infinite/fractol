/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:13:05 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 10:01:53 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_flagset4(const char *s, t_flags *flag, int *j)
{
	if ((flag->type_to_print == 3 || flag->type_to_print == 4 \
	|| flag->type_to_print == 8))
	{
		if (s[*j] == ' ' && flag->space_plus < 2)
			flag->space_plus = 1;
		else if (s[*j] == '+')
			flag->space_plus = 2;
	}
}

static void	ft_flagset3(const char *s, t_flags *flag, int *j)
{
	if (s[*j] == '.' && flag->type_to_print >= 1 && \
		flag->type_to_print <= 8)
	{
		(*j)++;
		flag->dot_size = 0;
		while (ft_isdigit(s[*j]))
		{
			flag->dot_size = flag->dot_size * 10 + (s[*j] - '0');
			(*j)++;
		}
		(*j)--;
		if (!(flag->type_to_print >= 2 && flag->type_to_print <= 8))
			flag->dot_size = -1;
	}
	else if (s[*j] == '0' && flag->after_or_before == 0 && \
		flag->type_to_print >= 3 && flag->type_to_print <= 8)
		flag->zero_or_space = 1;
	else if (s[*j] == '#' && flag->type_to_print >= 6 && \
		flag->type_to_print <= 7)
		flag->alternative = 1;
	ft_flagset4(s, flag, j);
}

static void	ft_flagset2(const char *s, t_flags *flag, int *j)
{
	if (s[*j] == '-' && flag->type_to_print != 9)
	{
		flag->zero_or_space = 0;
		flag->after_or_before = 1;
	}
	else if (ft_isdigit(s[*j]) && s[*j] != '0' && flag->type_to_print != 9)
	{
		flag->width = 0;
		while (ft_isdigit(s[*j]))
		{
			flag->width = flag->width * 10 + (s[*j] - '0');
			(*j)++;
		}
		(*j)--;
	}
	else
		ft_flagset3(s, flag, j);
}

int	ft_flagsset(const char *s, t_flags *flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!ft_mstrchr("csdiuxXp%", s[i]))
		i++;
	flag->type_to_print = ft_mstrchr("csdiuxXp%", s[i]);
	if (flag->type_to_print <= 0 || flag->type_to_print >= 10)
		return (-1);
	if (flag->type_to_print == 8)
		flag->alternative = 1;
	while (j < i && s[j] != '\0')
	{
		ft_flagset2(s, flag, &j);
		j++;
	}
	return (i + 1);
}
