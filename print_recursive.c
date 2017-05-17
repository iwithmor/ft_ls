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

void	print_directory_name(t_node *directory, t_request *this)
{
	if (this->options->big_r)
		ft_putstr(directory->path);
	else
		ft_putstr(directory->name);
	ft_putstr(":\n");
}

void	print_r_directory_name(t_node *dir, t_request *this, int iteration)
{
	if (!iteration)
		ft_putstr(dir->name);
	else
		ft_putstr(dir->path);
	ft_putstr(":\n");
	if (iteration && this->options->l)
	{
		if (dir->file_count != 0 || this->options->a)
			print_block_total(dir, this);
	}
}

void	print_r_directories(t_request *this)
{
	t_node	*current;
	int		count;

	count = 0;
	current = this->files;
	while (current)
	{
		if (is_directory(current))
		{
			if (count)
				ft_putchar('\n');
			++count;
			ls_recursive(current, this, 0);
		}
		current = current->next;
	}
}

void	print_recursive(t_node *dir, t_request *this, int iteration)
{
	if (this->options->a || dir->name[0] != '.')
	{
		ft_putchar('\n');
		ls_recursive(dir, this, ++iteration);
	}
}
