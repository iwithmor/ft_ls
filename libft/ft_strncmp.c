/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 20:58:48 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/26 20:58:50 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;
	size_t			i;

	i = 0;
	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (n)
	{
		if (s1cpy[i] != s2cpy[i])
			return (int)(s1cpy[i] - s2cpy[i]);
		if (s1cpy[i] == '\0' && s2cpy[i] == '\0')
			return (0);
		n--;
		i++;
	}
	return (0);
}
