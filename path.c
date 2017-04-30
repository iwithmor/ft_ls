/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_path(t_node *file, char *prefix)
{
	//printf("\nSETTING PATH FOR \"%s\" with prefix \"%s\"\t", file->name, prefix);
	if (ft_strequ(prefix, ""))
	{
		if (ft_strequ(file->name, "."))
			file->path = ft_strdup(file->name);
		else if (file->name[0] && file->name[0] == '/')
			file->path = ft_strdup(file->name);
		else
			file->path = concat_multiple(3, prefix, "/" , file->name);
	}
	else
		file->path = concat_multiple(3, prefix, "/" , file->name);
	//printf("path = %s\n", file->path);
}
