/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 22:14:38 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/30 22:14:39 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n)
{
	size_t count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (++count);
}

char	*ft_itoa(int n)
{
	char	*new;
	size_t	nlen;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nlen = ft_intlen(n);
	new = ft_strnew(nlen);
	if (!new)
		return (NULL);
	neg = 1;
	if (n < 0)
	{
		n = -n;
		neg = -neg;
	}
	while (--nlen > 0 && n > 9)
	{
		new[nlen] = (char)((n % 10) + '0');
		n /= 10;
	}
	new[nlen] = (char)(n + '0');
	if (neg == -1)
		new[0] = '-';
	return (new);
}
