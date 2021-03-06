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

void	reset_spacing(t_print *width)
{
	width->nlink = 0;
	width->owner = 0;
	width->group = 0;
	width->major = 0;
	width->minor = 0;
	width->size = 0;
}

void	set_size_spacing(t_node *f, t_print *width)
{
	int	len;

	if (is_device(f))
	{
		len = ft_strlen(ft_itoa(major(f->details->st_rdev)));
		if (len > width->major)
			width->major = len;
		len = ft_strlen(ft_itoa(minor(f->details->st_rdev)));
		if (len > width->minor)
			width->minor = len;
	}
	else
	{
		len = ft_strlen(ft_itoa(f->details->st_size));
		if (len > width->size)
			width->size = len;
	}
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
	if (len > width->owner)
		width->owner = len;
	if (group)
		len = ft_strlen(group->gr_name);
	else
		len = ft_strlen(ft_itoa(f->details->st_gid));
	if (len > width->group)
		width->group = len;
	len = ft_strlen(ft_itoa(f->details->st_nlink));
	if (len > width->nlink)
		width->nlink = len;
	set_size_spacing(f, width);
}

void	set_spacing_for_request(t_request *this)
{
	t_node	*current;

	if (!this->width && !(this->width = (t_print *)malloc(sizeof(t_print))))
		memory_error();
	reset_spacing(this->width);
	current = this->files;
	while (current)
	{
		set_spacing(current, this->width);
		current = current->next;
	}
	if (this->width->size < this->width->major + this->width->minor + 1)
		this->width->size = this->width->major + this->width->minor + 1;
}

void	set_spacing_for_directory(t_node *dir, t_request *this)
{
	t_node	*current;
	t_node	*parent;

	if (!dir->width && !(dir->width = (t_print *)malloc(sizeof(t_print))))
		memory_error();
	reset_spacing(dir->width);
	current = dir->sub;
	while (current)
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
	if (dir->width->size < dir->width->major + dir->width->minor + 1)
		dir->width->size = dir->width->major + dir->width->minor + 1;
}
