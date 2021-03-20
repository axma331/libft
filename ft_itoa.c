/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:48:24 by feschall          #+#    #+#             */
/*   Updated: 2020/11/26 16:50:30 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(int n)
{
	int			i;
	long int	j;

	i = 1;
	j = n;
	if (j < 0)
	{
		j = -j;
		i++;
	}
	while (j > 9)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*str;
	long int	num;
	int			i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * count(n) + 1)))
		return (0);
	if (n < 0)
		str[0] = '-';
	num = n;
	if (num < 0)
		num = -num;
	str[count(n) - i++] = '\0';
	while (num > 9)
	{
		str[count(n) - i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	str[count(n) - i] = (num % 10) + '0';
	return (str);
}
