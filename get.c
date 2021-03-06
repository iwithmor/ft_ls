/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_linked_path(t_node *directory)
{
	char	*linked_path;

	if (!(linked_path = (char *)ft_memalloc(PATH_MAX)))
		memory_error();
	readlink(directory->path, linked_path, PATH_MAX - 1);
	return (linked_path);
}

void	get_directory_contents(t_node *directory, t_request *this)
{
	DIR				*d;
	struct dirent	*contents;
	t_node			*file;

	d = NULL;
	if (is_link(directory) && is_link_to_directory(directory))
		d = opendir(get_linked_path(directory));
	else if (is_directory(directory))
		d = opendir(directory->path);
	if (d)
	{
		while ((contents = readdir(d)) != NULL)
		{
			if (!this->options->a && ft_strequ(contents->d_name, "."))
				continue ;
			else if (!this->options->a && ft_strequ(contents->d_name, ".."))
				continue ;
			file = new_file(contents->d_name, directory->path);
			if (file)
				add_file_to_directory(file, directory);
		}
		closedir(d);
	}
}

void	get_sub_files(t_request *this)
{
	t_node	*current;

	current = this->files;
	while (current)
	{
		if (is_directory(current))
		{
			get_directory_contents(current, this);
			sort_directory_files(current, this);
		}
		current = current->next;
	}
}

void	get_files(int start, int end, char **argv, t_request *this)
{
	t_node *new;

	if (start == end)
	{
		new = new_file(".", "");
		if (new)
			add_file_to_request(new, this);
	}
	while (start < end)
	{
		if (ft_strequ(argv[start], "."))
			new = new_file(".", "");
		else if (argv[start][0] == '/')
			new = new_file(argv[start], "");
		else
			new = new_file(argv[start], ".");
		if (new)
			add_file_to_request(new, this);
		else
			add_file_as_invalid(argv[start], this);
		++start;
	}
	get_sub_files(this);
	sort_invalid_files(this);
	print_invalid_files(this);
}
