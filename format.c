/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_formatted_number(int n, int width)
{
	char *number_string;
	int len;

	number_string = ft_itoa(n);
	len = ft_strlen(number_string);
	if (len <= width)
	{
		while (len < width)
		{
			ft_putchar(' ');
			len++;
		}
		ft_putstr(number_string);
	}
	else
		ft_putstr(ft_memchr(ft_strnew(width), '0', width));
}

void	print_formatted_string(char *str, int width)
{
	int len;

	len = ft_strlen(str);
	if (len <= width)
	{
		ft_putstr(str);
		while (len < width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	else
		ft_putstr(ft_strsub(str, 0, width));
}
