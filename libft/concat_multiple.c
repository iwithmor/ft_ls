/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_multiple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	concat_strings(char *new, char **strings, int string_count)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	while (i < string_count)
	{
		j = 0;
		while (j < (int)ft_strlen(strings[i]))
		{
			new[x] = strings[i][j];
			x++;
			j++;
		}
		i++;
	}
}

char	*concat_multiple(int count, ...)
{
	va_list	string_list;
	char	**string_array;
	int		i;
	char	*new;
	int		len;

	va_start(string_list, count);
	string_array = (char **)ft_memalloc(sizeof(char *) * count);
	i = 0;
	len = 0;
	while (i < count)
	{
		string_array[i] = va_arg(string_list, char *);
		len += ft_strlen(string_array[i]);
		i++;
	}
	new = (char *)ft_memalloc(len + 1);
	concat_strings(new, string_array, count);
	va_end(string_list);
	return (new);
}
