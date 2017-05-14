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

void	print_dots(t_node *directory, t_request *this)
{
	t_node	*parent;
	t_node	*current;

	if (!this->options->l)
	{
		if (!this->options->r)
			ft_putstr(".\n..\n");
		else
			ft_putstr("..\n.\n");
	}
	else
	{
		current = copy_file(ft_strdup("."), directory->path);
		parent = copy_file(ft_strdup(".."), get_parent_path(directory));
		if (!this->options->r)
		{
			print_long_version(current, directory->width);
			ft_putchar('\n');
		}
		print_long_version(parent, directory->width);
		ft_putchar('\n');
		if (this->options->r)
		{
			print_long_version(current, directory->width);
			ft_putchar('\n');
		}
	}
}

void	print_files_from_directory(t_node *directory, t_request *this)
{
	t_node *current;
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
	t_node *current;
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
	if (this->options->a && !this->options->r)
		print_dots(dir, this);
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
	if (this->options->a && this->options->r)
		print_dots(dir, this);
}

//
void	print_directories(t_request *this)
{
	t_node	*current;
	int		count;

	count = 0;
	current = this->files;
	if (this->file_count == 1 && is_directory(current))
	{
		if (this->arg_count > 1)
		{
			if (this->options->R)
				ft_putstr(current->path);
			else
				ft_putstr(current->name);
			ft_putstr(":\n");
		}
		if (this->options->l)
		{
			ft_putstr("total ");
			ft_putnbr(total_blocks(current, this));
			ft_putchar('\n');
		}
		print_directory_contents(this->files, this);
		return ;
	}
	while (current)
	{
		if (is_directory(current))
		{
			if (count)
				ft_putchar('\n');
			++count;
			if (this->options->R)
				ft_putstr(current->path);
			else
				ft_putstr(current->name);
			ft_putstr(":\n");
			if (this->options->l)
			{
				ft_putstr("total ");
				ft_putnbr(total_blocks(current, this));
				ft_putchar('\n');
			}
			print_directory_contents(current, this);
		}
		current = current->next;
	}
}

void	print_files(t_request *this)
{
	t_node *current;
	int		count;
	int		count2;

	count = 0;
	count2 = 0;
	current = this->files;
	while (current)
	{
		if (!is_directory(current))
		{
			count++;
			if (this->options->l)
				print_long_version(current, this->width);
			else
				ft_putstr(current->name);
			ft_putchar('\n');
		}
		else
			++count2;
		current = current->next;
	}
}
