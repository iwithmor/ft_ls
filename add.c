/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_file_to_request(t_node *new_file, t_request *this)
{
	t_node *current;

	if (is_directory(new_file))
		this->directory_count++;
	if (this->file_count == 0)
		this->files = new_file;
	else
	{
		current = this->files;
		while (current->next != NULL)
			current = current->next;
		current->next = new_file;
		new_file->next = NULL;
	}
	this->file_count++;
}

void	add_file_to_directory(t_node *file, t_node *directory)
{
	t_node *current;

	//printf("ADDING FILE (\"%s\") TO DIRECTORY (\"%s\")\n", file->name, directory->name);
	set_path(file, directory->path);
	if (directory->file_count == 0)
		directory->sub = file;
	else
	{
		current = directory->sub;
		while (current->next != NULL)
			current = current->next;
		current->next = file;
		file->next = NULL;
	}
	directory->file_count++;
}
