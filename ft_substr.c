/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:56:40 by feschall          #+#    #+#             */
/*   Updated: 2020/11/26 15:04:06 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned char	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	if (start < ft_strlen(s) + 1)
	{
		while (i < len && s[start + 1])
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
