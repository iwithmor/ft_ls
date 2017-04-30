/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:14:47 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/26 16:14:49 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;

	dstlen = ft_strlen((const char *)dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (srclen + size);
	dst += dstlen;
	size -= dstlen;
	while (*src != '\0' && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (srclen + dstlen);
}
