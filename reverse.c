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

void	swap_down(t_request *this, int swaps)
{
	t_node	*current;

	current = this->files;
	while (swaps)
	{
		current = swap_request_files(current, current->next, this);
		--swaps;
	}
}

void	directory_swap_down(t_node *directory, int swaps)
{
	t_node	*current;

	current = directory->sub;
	while (swaps)
	{
		current = swap_directory_files(current, current->next, directory);
		--swaps;
	}
}

void	reverse_files(t_request *this)
{
	int		swaps;

	swaps = this->file_count - 1;
	while (swaps > 0)
	{
		swap_down(this, swaps);
		--swaps;
	}
}

void	reverse_directory_files(t_node *directory)
{
	int		swaps;

	swaps = directory->file_count - 1;
	while (swaps > 0)
	{
		directory_swap_down(directory, swaps);
		--swaps;
	}
}
