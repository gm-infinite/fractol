/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:12:16 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/12/06 09:31:52 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_atoiwriter(char *itoa, size_t isneg, size_t size, long temp)
{
	if (temp < 0)
	{
		isneg = 1;
		temp = temp * -1;
	}
	if (isneg)
		itoa[0] = '-';
	itoa[size] = '\0';
	while (size > isneg)
	{
		itoa[size - 1] = (char)((temp % 10) + 48);
		temp = temp / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*itoa;
	size_t	isneg;
	long	temp;

	isneg = 0;
	size = 0;
	temp = (long)n;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	itoa = (char *)malloc(sizeof(char) * (size + 1));
	if (!itoa)
		return (NULL);
	ft_atoiwriter(itoa, isneg, size, temp);
	return (itoa);
}
