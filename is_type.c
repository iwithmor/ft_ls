/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_link(t_node *file)
{
	return S_ISLNK(file->details->st_mode);
}

int	is_link_to_directory(t_node *file)
{
	t_stat *link_info;

	if (!(link_info = (t_stat *) ft_memalloc(sizeof(t_stat))))
		memory_error();
	if (lstat(file->path, link_info) == -1)
	{
		if (stat(file->path, link_info) == -1)
			return (0);
		else
			return (S_ISDIR(link_info->st_mode));
	}
	if (S_ISDIR(link_info->st_mode))
	{
		free(link_info);
		return (1);
	}
	free(link_info);
	if (!(link_info = (t_stat *) ft_memalloc(sizeof(t_stat))))
		memory_error();
	if (stat(file->path, link_info) == -1)
		return (0);
	if (S_ISDIR(link_info->st_mode))
	{
		free(link_info);
		return (1);
	}
	return (0);
}

int	is_directory(t_node *file)
{
	if (S_ISDIR(file->details->st_mode))
		return (1);
	if (!is_link(file))
		return (0);
	return (is_link_to_directory(file));
}

int	is_current_year(char *year)
{
	time_t	today;
	char	**today_split;
	char	*current_year;

	time(&today);
	today_split = ft_strsplit(ft_strtrim(ctime(&today)), ' ');
	current_year = today_split[YEAR];
	return (ft_strequ(year, current_year));
}
