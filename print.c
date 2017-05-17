/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files_from_directory(t_node *directory, t_request *this)
{
	t_node	*current;
	int		count;

	count = 0;
	current = directory->sub;
	while (current && !is_directory(current))
	{
		if (this->options->a || current->name[0] != '.')
		{
			count++;
			if (this->options->l)
				print_long_version(current, directory->width);
			else
				ft_putstr(current->name);
			ft_putchar('\n');
		}
		current = current->next;
	}
}

void	print_directory_contents(t_node *dir, t_request *this)
{
	t_node	*current;
	int		count;

	count = 0;
	if (!has_permission(dir->details->st_mode, S_IROTH))
	{
		ls_error(dir->name, "Permission denied");
		return ;
	}
	if (!dir->width)
		set_spacing_for_directory(dir, this);
	current = dir->sub;
	while (current)
	{
		if (this->options->a || current->name[0] != '.')
		{
			count++;
			if (this->options->l)
				print_long_version(current, dir->width);
			else
				ft_putstr(current->name);
			ft_putchar('\n');
		}
		current = current->next;
	}
}

void	print_single_directory(t_request *this)
{
	t_node	*current;

	current = this->files;
	if (this->arg_count > 1)
		print_directory_name(current, this);
	if (this->options->l && current->file_count != 0)
		print_block_total(current, this);
	if (current->file_count == 0 && is_link(current) && this->options->l)
	{
		print_long_version(current, this->width);
		ft_putchar('\n');
	}
	else
		print_directory_contents(current, this);
}

void	print_directories(t_request *this)
{
	t_node	*current;
	int		count;

	count = 0;
	current = this->files;
	if (this->file_count == 1 && is_directory(current))
	{
		print_single_directory(this);
		return ;
	}
	while (current)
	{
		if (is_directory(current))
		{
			if (count)
				ft_putchar('\n');
			++count;
			print_directory_name(current, this);
			if (this->options->l)
				print_block_total(current, this);
			print_directory_contents(current, this);
		}
		current = current->next;
	}
}

void	print_files(t_request *this)
{
	t_node	*current;

	current = this->files;
	while (current)
	{
		if (!is_directory(current))
		{
			if (this->options->l)
				print_long_version(current, this->width);
			else
				ft_putstr(current->name);
			ft_putchar('\n');
		}
		current = current->next;
	}
}
