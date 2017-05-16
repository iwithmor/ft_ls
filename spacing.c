/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	adjust_size_spacing(t_print *width)
{
	if (width->size < width->major + width->minor + 1)
		width->size = width->major + width->minor + 1;
}

void	set_spacing(t_node *f, t_print *width)
{
	struct passwd	*owner;
	struct group	*group;
	int				len;

	owner = getpwuid(f->details->st_uid);
	group = getgrgid(f->details->st_gid);
	if (owner)
		len = ft_strlen(owner->pw_name);
	else
		len = ft_strlen(ft_itoa(f->details->st_uid));
	width->owner = (len > width->owner) ? len : width->owner;
	if (group)
		len = ft_strlen(group->gr_name);
	else
		len = ft_strlen(ft_itoa(f->details->st_gid));
	width->group = (len > width->group) ? len : width->group;
	len = ft_strlen(ft_itoa(f->details->st_nlink));
	width->nlink = (len > width->nlink) ? len : width->nlink;
	if (is_device(f))
	{
		len = ft_strlen(ft_itoa(major(f->details->st_rdev)));
		width->major = (len > width->major) ? len : width->major;
		len = ft_strlen(ft_itoa(minor(f->details->st_rdev)));
		width->minor = (len > width->minor) ? len : width->minor;
	}
	else
	{
		len = ft_strlen(ft_itoa(f->details->st_size));
		width->size = (len > width->size) ? len : width->size;
	}
}

void	set_spacing_for_request(t_request *this)
{
	t_node	*current;

	if (!this->width && !(this->width = (t_print *) malloc(sizeof(t_print))))
		memory_error();
	this->width->nlink = 0;
	this->width->owner = 0;
	this->width->group = 0;
	this->width->major = 0;
	this->width->minor = 0;
	this->width->size = 0;
	current = this->files;
	while(current)
	{
		set_spacing(current, this->width);
		current = current->next;
	}
	adjust_size_spacing(this->width);
}

void	set_spacing_for_directory(t_node *dir, t_request *this)
{
	t_node	*current;
	t_node	*parent;

	if (!dir->width && !(dir->width = (t_print *) malloc(sizeof(t_print))))
		memory_error();
	dir->width->nlink = 0;
	dir->width->owner = 0;
	dir->width->group = 0;
	dir->width->major = 0;
	dir->width->minor = 0;
	dir->width->size = 0;
	current = dir->sub;
	while(current)
	{
		if (this->options->a)
			set_spacing(current, dir->width);
		else if (current->name[0] != '.')
			set_spacing(current, dir->width);
		current = current->next;
	}
	if (this->options->a)
	{
		parent = copy_file(ft_strdup(".."), get_parent_path(dir));
		set_spacing(dir, dir->width);
		set_spacing(parent, dir->width);
	}
	adjust_size_spacing(dir->width);
}
