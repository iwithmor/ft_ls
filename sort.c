/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_request_files(t_request *this)
{
	t_node	*current;
	int		bubble;

	if (this->file_count <= 1)
		return ;
	bubble = 0;
	while (bubble++ < this->file_count)
	{
		current = this->files;
		while (current && current->next)
			current = compare_and_swap(current, this);
	}
	if (this->options->r)
		reverse_files(this);
}

void	sort_directory_files(t_node *directory, t_request *this)
{
	t_node	*current;
	int		bubble;

	if (directory->file_count <= 1)
		return ;
	bubble = 0;
	while (bubble++ < directory->file_count)
	{
		current = directory->sub;
		while (current && current->next)
			current = dir_comp_and_swap(current, directory, this);
	}
	if (this->options->r)
		reverse_directory_files(directory);
}

void	sort(t_request *this)
{
	if (this->file_count == 1 && is_directory(this->files))
	{
		sort_directory_files(this->files, this);
		return ;
	}
	if (this->file_count <= 1)
		return ;
	sort_request_files(this);
}

void	sort_invalid_files(t_request *this)
{
	t_invalid	*current;
	int			bubble;

	if (this->err_count <= 1)
		return ;
	bubble = 0;
	while (bubble++ < this->err_count)
	{
		current = this->err_files;
		while (current && current->next)
			current = compare_and_swap_err(current, this);
	}
}
