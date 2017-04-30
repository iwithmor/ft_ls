/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:51:12 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/30 15:07:37 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;
	size_t			i;

	if (len == 0 || dst == src)
		return (dst);
	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			dstcpy[i] = srccpy[i];
			i++;
		}
		return (dst);
	}
	while (--len > 0)
		dstcpy[len] = srccpy[len];
	dstcpy[len] = srccpy[len];
	return (dst);
}
