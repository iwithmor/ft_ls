/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_r_directory_name(t_node *dir, t_request *this, int iteration)
{
	if (!iteration)
			ft_putstr(dir->name);
	else
		ft_putstr(dir->path);
	ft_putstr(":\n");
	if (iteration && this->options->l)
	{
		ft_putstr("total ");
		ft_putnbr(total_blocks(dir, this));
		ft_putchar('\n');
	}
}

void	print_recursive(t_node *dir, t_request *this, int iteration)
{
	if (this->options->a)
	{
		ft_putchar('\n');
		ls_recursive(dir, this, ++iteration);
	}
	else if (dir->name[0] != '.')
	{
		ft_putchar('\n');
		ls_recursive(dir, this, ++iteration);
	}
}
