/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		total_blocks(t_node *directory, t_request *this)
{
	int		total;
	t_node	*current;

	total = 0;
	current = directory->sub;
	while (current)
	{
		if (this->options->a)
			total += current->details->st_blocks;
		else if (current->name[0] != '.')
			total += current->details->st_blocks;
		current = current->next;
	}
	return (total);
}

void	print_block_total(t_node *file, t_request *this)
{
	ft_putstr("total ");
	ft_putnbr(total_blocks(file, this));
	ft_putchar('\n');
}
