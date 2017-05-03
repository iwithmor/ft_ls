/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	memory_error(void)
{
	ft_putstr("Not enough memory.\n");
	exit(1);
}

void	illegal_option(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ls ");
	ft_putstr("[-lRart] [file ...]\n");
	exit(1);
}

void	invalid_file(char *s)
{
	ft_putstr("ls: ");
	ft_putstr(s);
	ft_putstr(": No such file or directory\n");
	exit(1);
}

void	ls_error(char *filename, char *error)
{
	ft_putstr("ls: ");
	ft_putstr(filename);
	ft_putstr(": ");
	ft_putstr(error);
	ft_putstr("\n");
}
