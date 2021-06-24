/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:40:56 by feschall          #+#    #+#             */
/*   Updated: 2021/06/25 01:13:48 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	count(char const *s, char c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			l++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (l);
}

static char	**freelloc(char **s, int i)
{
	while (i != 0)
	{
		free(s[i]);
		i--;
	}
	free(s[i]);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		m;

	i = 0;
	m = 0;
	if (!s || !(arr = (char **)malloc(sizeof(char *) * (count(s, c) + 1))))
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			if (!(arr[m] = (char *)malloc(sizeof(char) * (len(s + i, c) + 1))))
				return (freelloc(arr, m));
			while (s[i] && s[i] != c)
				arr[m][j++] = s[i++];
			arr[m++][j] = 0;
		}
	}
	arr[m] = 0;
	return (arr);
}
