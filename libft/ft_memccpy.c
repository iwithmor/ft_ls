/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:50:57 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/29 12:50:58 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dstcpy;
	unsigned char *srccpy;
	unsigned char uc;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	uc = (unsigned char)c;
	while (n--)
	{
		*dstcpy = *srccpy;
		if (*dstcpy == uc)
			return (++dstcpy);
		dstcpy++;
		srccpy++;
	}
	return (NULL);
}
