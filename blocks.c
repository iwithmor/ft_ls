/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	total_blocks(t_node *directory)
{
	int		total;
	t_node	*current;

	total = 0;
	current = directory->sub;
	while (current)
	{
		total += current->details->st_blocks;
		current = current->next;
	}
	return(total);
}
