/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_recursive(t_node *directory, t_request *this, int iteration)
{
	t_node	*current;

	if (iteration)
	{
		ft_putstr("\n");	
		ft_putstr(directory->path);
		ft_putstr(":\n");
	}
	if (directory->file_count == 0)
		get_directory_contents(directory);
	print_directory_contents(directory, this);
	current = directory->sub;
	while (current)
	{
		if (is_directory(current))
		{
			if (!iteration || this->options->a)
				ls_recursive(current, this, ++iteration);
			else if (current->name[0] != '.')
				ls_recursive(current, this, ++iteration);
		}
		current = current->next;
	}
}

void	ls(t_request *this)
{
	t_node		*current;

	//printf("STARTING LS\n");
	sort(this);
	print_files(this);
	if (!this->options->R)
		print_directories(this);
	else
	{
		//printf("RECURSIVE REQUEST FOUND\n");
		current = this->files;
		//if (!current)
		//	printf("(null)\n");
		while (current)
		{
			if (is_directory(current))
				ls_recursive(current, this, 0);
			current = current->next;
		}
	}
}

int		main(int argc, char **argv)
{
	t_request	*request;
	int			arg_start_index;

	request = new_request();
	arg_start_index = get_options(argc, argv, request);
	request->arg_count = argc - arg_start_index;
	get_files(arg_start_index, argc, argv, request);
	ls(request);
	//	TO DO:	Do all the hard stuff
	return (0);
}
