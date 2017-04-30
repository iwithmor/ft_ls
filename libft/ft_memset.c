/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:50:27 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/29 12:50:29 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *bcpy;
	unsigned char uc;

	bcpy = (unsigned char *)b;
	uc = (unsigned char)c;
	while (len--)
		*bcpy++ = uc;
	return (b);
}
