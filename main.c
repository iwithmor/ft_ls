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
	t_node		*current;

	if (directory->file_count == 0)
	{
		get_directory_contents(directory);
		sort_directory_files(directory, this);
	}
	if (iteration || this->arg_count > 1)
		print_r_directory_name(directory, this, iteration);
	if (this->options->l)
		set_spacing_for_directory(directory, this);
	print_directory_contents(directory, this);
	current = directory->sub;
	while (current)
	{
		if (is_directory(current))
			print_recursive(current, this, iteration);
		current = current->next;
	}
}

void	ls(t_request *this)
{
	t_node	*current;
	int		count;

	count = 0;
	sort(this);
	if (this->options->l)
		set_spacing_for_request(this);
	if (!this->arg_count && this->options->l && this->options->R)
	{
		ft_putstr("total ");
		ft_putnbr(total_blocks(this->files, this));
		ft_putchar('\n');
	}
	print_files(this);
	if (this->directory_count && this->directory_count != this->file_count)
		ft_putchar('\n');
	if (!this->options->R)
		print_directories(this);
	else
	{
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
	return (0);
}
