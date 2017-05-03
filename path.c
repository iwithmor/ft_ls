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
}

char	*get_parent_path(t_node *file)
{
	char	*last_slash;
	int		slash_count;
	int	len;

	if (ft_strequ(file->path, "."))
		return(ft_strdup(".."));
	len = ft_strlen(file->path);
	slash_count = 0;
	while (--len)
		slash_count += (file->path[len] == '/') ? 1 : 0;
	len = ft_strlen(file->path);
	last_slash = ft_strrchr(file->path, '/');
	if (!last_slash || last_slash == file->path)
		return (NULL);
	if (slash_count == len || file->path - last_slash == len - 1)
		return (NULL);
	return (ft_strsub(file->path, 0, last_slash - file->path));
}
