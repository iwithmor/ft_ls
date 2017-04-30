/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 22:14:17 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/30 22:14:18 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t count;
	size_t n;

	count = 0;
	n = 0;
	while (*s != '\0')
	{
		if (*s == c)
			n = 0;
		else if (n == 0)
		{
			n++;
			count++;
		}
		s++;
	}
	return (count);
}

size_t	ft_substrlen(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	new = (char **)malloc(sizeof(*new) * (count + 1));
	i = 0;
	if (!new)
		return (NULL);
	while (count > 0)
	{
		while (*s != '\0' && *s == c)
			s++;
		new[i] = ft_strsub(s, 0, ft_substrlen(s, c));
		if (!new)
			return (NULL);
		s += ft_substrlen(s, c);
		i++;
		count--;
	}
	new[i] = NULL;
	return (new);
}
