/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:41:32 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/26 15:41:39 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1len;

	s1len = ft_strlen(s1);
	ft_strncpy(&s1[s1len], s2, n);
	s1[s1len + n] = '\0';
	return (s1);
}
