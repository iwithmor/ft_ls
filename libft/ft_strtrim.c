/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 22:02:54 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/30 22:02:56 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*new;
	size_t			len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i < len && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (len != 0)
		len--;
	while (len > i && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	len++;
	new = ft_strsub(s, i, len - i);
	return (new);
}
