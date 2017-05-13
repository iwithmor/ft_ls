/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long	time_cmp(t_node *n1, t_node *n2)
{
	long time1;
	long time2;

	time1 = n1->details->st_mtime;
	time2 = n2->details->st_mtime;
	if (time1 == time2)
		return (ft_strcmp(n1->name, n2->name));
	return(time2 - time1);
}

t_node	*compare_and_swap(t_node *current, t_request *this)
{
	long compare_factor;

	if (this->options->t)
		compare_factor = time_cmp(current, current->next);
	else
	{
		compare_factor = ft_strcmp(current->name, current->next->name);
		if (compare_factor == 0)
			compare_factor = time_cmp(current, current->next);
	}
	if (this->options->r && compare_factor < 0)
		return (swap_request_files(current, current->next, this));
	else if (!this->options->r && compare_factor > 0)
		return (swap_request_files(current, current->next, this));
	return current->next;
}

t_node	*directory_compare_and_swap(t_node *file, t_node *d, t_request *this)
{
	long compare_factor;

	if (this->options->t)
		compare_factor = time_cmp(file, file->next);
	else
		compare_factor = ft_strcmp(file->name, file->next->name);
	if (this->options->r && compare_factor < 0)
		return (swap_directory_files(file, file->next, d));
	else if (!this->options->r && compare_factor > 0)
		return (swap_directory_files(file, file->next, d));
	return file->next;
}
