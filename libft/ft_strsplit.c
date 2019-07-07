/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:49:03 by kamako            #+#    #+#             */
/*   Updated: 2019/06/29 03:22:07 by kamako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_wordcnt(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int			ft_wordlen(const char *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s != '0')
	{
		len++;
		s++;
	}
	return (len);
}

char				**ft_strsplit(const char *s, char c)
{
	int		j;
	int		i;
	char	**tab;

	i = 0;
	if (!s || !c)
		return (NULL);
	j = ft_wordcnt((const char *)s, c);
	tab = (char **)malloc(sizeof(*tab) * (ft_wordcnt((const char *)s, c)) + 1);
	if (tab == NULL)
		return (NULL);
	while (j--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char *)s, 0, ft_wordlen((const char *)s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_wordlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
