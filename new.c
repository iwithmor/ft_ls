/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_request	*new_request(void)
{
	t_request	*new;

	//printf("CREATING NEW REQUEST\n");
	if (!(new = (t_request *) ft_memalloc(sizeof(t_request))))
		memory_error();
	else if (!(new->options = (t_args *) ft_memalloc(sizeof(t_args))))
		memory_error();
	clear_options(new->options);
	new->file_count = 0;
	return (new);
}

t_node	*new_file(char *filename, char *prefix)
{
	t_node *new;

	//printf("CREATING NEW FILE \"%s\"\n", filename);
	if (!(new = (t_node *) ft_memalloc(sizeof(t_node))))
		memory_error();
	new->name = ft_strdup(filename);
	if (!(new->details = (t_stat *) ft_memalloc(sizeof(t_stat))))
		memory_error();
	set_path(new, prefix);
	if (lstat(new->path, new->details) == -1)
	{
		ls_error(new->name, strerror(errno));
		free(new->name);
		free(new->details);
		new->name = NULL;
		new->details = NULL;
		return (NULL);
	}
	return (new);
}
