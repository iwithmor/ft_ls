/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 22:26:56 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/23 22:26:58 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *scpy;
	unsigned char uc;

	scpy = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*scpy == uc)
			return (void *)(scpy);
		scpy++;
	}
	return (NULL);
}
