/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:59:38 by feschall          #+#    #+#             */
/*   Updated: 2020/11/26 20:01:46 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (s[i] && (('\t' <= s[i] && s[i] <= '\r') || s[i] == ' '))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && ('0' <= s[i] && s[i] <= '9'))
	{
		num = 10 * num + (s[i] - '0') * sign;
		i++;
	}
	return (num);
}
