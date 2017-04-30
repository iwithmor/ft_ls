/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:59:37 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/27 15:59:39 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_findmatch(char *big, char *little, size_t match, size_t len)
{
	int i;

	i = 0;
	while (little[i] != '\0')
	{
		if (len < ft_strlen(little) || big[i] != little[i])
		{
			match = 0;
			break ;
		}
		match++;
		i++;
	}
	return (match);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t match;

	match = 0;
	if (ft_strcmp(little, "") == 0)
		return (char *)(big);
	if (len >= ft_strlen(big))
		return (ft_strstr(big, little));
	while (len >= ft_strlen(little))
	{
		if (*big == little[0])
		{
			match = ft_findmatch((char *)big, (char *)little, match, len);
			if (match > 0)
				return (char *)(big);
		}
		big++;
		len--;
	}
	return (NULL);
}
