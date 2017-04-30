/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:59:16 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/26 17:59:21 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int match;

	i = -1;
	match = 0;
	if (!*little)
		return (char *)(big);
	while (big[++i] != '\0')
	{
		j = 0;
		while (little[j] != '\0')
		{
			if (big[i + j] == '\0' || little[j] != big[i + j])
			{
				match = 0;
				break ;
			}
			j++;
			match++;
		}
		if (match > 0)
			return (char *)(big + i);
	}
	return (NULL);
}
