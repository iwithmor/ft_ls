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
	t_node *current;

	//printf("PRINTING FILES FROM DIRECTORY (\"%s\")\n", directory->name);
	current = directory->sub;
	while (current && !is_directory(current))
	{
		if (this->options->a || current->name[0] != '.')
		{
			if (this->options->l)
				print_long_version(current);
			else
				ft_putstr(current->name);
			ft_putchar('\n');
		}
		current = current->next;
	}
}

void	print_directory_contents(t_node *directory, t_request *this)
{
	t_node *current;

	//printf("PRINTING ALL FILES FROM DIRECTORY (\"%s\")\n", directory->name);
	current = directory->sub;
	if (this->options->a)
		ft_putstr(".\n..\n");
	while (current)
	{
		if (this->options->a || current->name[0] != '.')
		{
			if (this->options->l)
				print_long_version(current);
			else
				ft_putstr(current->name);
			ft_putchar('\n');
		}
		current = current->next;
	}
}

void	print_directories(t_request *this)
{
	t_node	*current;
	int		count;

	//printf("PRINTING ALL REQUESTED DIRECTORIES\n");
	count = 0;
	if (this->file_count == 1 && is_directory(this->files))
	{
		if (this->arg_count > 1)
		{
			if (this->options->R)
				ft_putstr(current->path);
			else
				ft_putstr(current->name);
			ft_putstr(":\n");
		}
		print_directory_contents(this->files, this);
		return ;
	}
	current = this->files;
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
			print_directory_contents(current, this);
		}
		current = current->next;
	}
}

void	print_files(t_request *this)
{
	t_node *current;

	//printf("PRINTING ALL REQUESTED FILES\n");
	current = this->files;
	while (current)
	{
		if (!is_directory(current))
		{
			if (this->options->l)
				print_long_version(current);
			else
				ft_putstr(current->name);
			ft_putchar('\n');
		}
		current = current->next;
	}
}
