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
	ft_putstr_fd("Not enough memory.\n", 2);
	exit(1);
}

void	illegal_option(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls ", 2);
	ft_putstr_fd("[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 2);
	exit(1);
}

void	invalid_file(char *s)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	exit(1);
}

void	ls_error(char *filename, char *error)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
}

void	print_invalid_files(t_request *this)
{
	t_invalid	*current;

	current = this->err_files;
	while (current)
	{
		ls_error(current->name, "No such file or directory");
		current = current->next;
	}
}
