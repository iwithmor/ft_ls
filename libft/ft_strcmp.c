/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 20:36:41 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/26 20:36:43 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s1cpy;
	unsigned char *s2cpy;

	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (*s1cpy && *s2cpy)
	{
		if (*s1cpy != *s2cpy)
			return (int)(*s1cpy - *s2cpy);
		s1cpy++;
		s2cpy++;
	}
	if (*s1cpy || *s2cpy)
		return (int)(*s1cpy - *s2cpy);
	return (0);
}
