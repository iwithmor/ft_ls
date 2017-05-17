/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node	*swap_request_files(t_node *n1, t_node *n2, t_request *this)
{
	t_node	*previous;

	previous = this->files;
	if (previous == n1)
	{
		n1->next = n2->next;
		n2->next = n1;
		this->files = n2;
	}
	else
	{
		while (previous && previous->next && previous->next != n1)
			previous = previous->next;
		n1->next = n2->next;
		n2->next = n1;
		previous->next = n2;
	}
	return (n1);
}

t_node	*swap_directory_files(t_node *n1, t_node *n2, t_node *directory)
{
	t_node	*previous;

	previous = directory->sub;
	if (previous == n1)
	{
		n1->next = n2->next;
		n2->next = n1;
		directory->sub = n2;
	}
	else
	{
		while (previous && previous->next && previous->next != n1)
			previous = previous->next;
		n1->next = n2->next;
		n2->next = n1;
		previous->next = n2;
	}
	return (n1);
}

t_invalid	*swap_invalid_files(t_invalid *n1, t_invalid *n2, t_request *this)
{
	t_invalid	*previous;

	previous = this->err_files;
	if (previous == n1)
	{
		n1->next = n2->next;
		n2->next = n1;
		this->err_files = n2;
	}
	else
	{
		while (previous && previous->next && previous->next != n1)
			previous = previous->next;
		n1->next = n2->next;
		n2->next = n1;
		previous->next = n2;
	}
	return (n1);
}
