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

long		time_cmp(t_node *n1, t_node *n2)
{
	long time1;
	long time2;

	time1 = n1->details->st_mtime;
	time2 = n2->details->st_mtime;
	if (time1 == time2)
	{
		time1 = n1->details->st_mtimespec.tv_nsec;
		time2 = n2->details->st_mtimespec.tv_nsec;
		if (time1 == time2)
			return (ft_strcmp(n1->name, n2->name));
	}
	return (time2 - time1);
}

t_node		*compare_and_swap(t_node *current, t_request *this)
{
	long compare_factor;

	if (this->options->t)
		compare_factor = time_cmp(current, current->next);
	else
		compare_factor = ft_strcmp(current->name, current->next->name);
	if (compare_factor > 0)
		return (swap_request_files(current, current->next, this)->next);
	return (current->next);
}

t_node		*dir_comp_and_swap(t_node *f, t_node *d, t_request *this)
{
	long compare_factor;

	if (this->options->t)
		compare_factor = time_cmp(f, f->next);
	else
		compare_factor = ft_strcmp(f->name, f->next->name);
	if (compare_factor > 0)
		return (swap_dir_files(f, f->next, d)->next);
	return (f->next);
}

t_invalid	*compare_and_swap_err(t_invalid *f, t_request *this)
{
	long compare_factor;

	compare_factor = ft_strcmp(f->name, f->next->name);
	if (compare_factor > 0)
		return (swap_err(f, f->next, this)->next);
	return (f->next);
}
