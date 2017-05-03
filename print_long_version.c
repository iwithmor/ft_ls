/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_version.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file_type(mode_t st_mode)
{
	char type;

	if (S_ISREG(st_mode))
		type = '-';
	else if (S_ISDIR(st_mode))
		type = 'd';
	else if (S_ISBLK(st_mode))
		type = 'b';
	else if (S_ISCHR(st_mode))
		type = 'c';
	else if (S_ISLNK(st_mode))
		type = 'l';
	else if (S_ISSOCK(st_mode))
		type = 's';
	else
		type = '-';
	ft_putchar(type);
}

void	print_owners(t_stat *details, int owner_width, int group_width)
{
	struct passwd  *user;
	struct group   *group;

	user = getpwuid(details->st_uid);
	group = getgrgid(details->st_gid);
	if (user)
		print_formatted_string_left(user->pw_name, owner_width);
	else
		print_formatted_number(details->st_uid, owner_width);
	ft_putstr("  ");
	if (group)
		print_formatted_string_left(group->gr_name, group_width);
	else
		print_formatted_number(details->st_gid, group_width);
}

void	print_date_and_time(time_t modification_time)
{
	char	*date_time_string;
	char	**date_elements;
	char	**time_elements;


	date_time_string = ft_strtrim(ctime(&modification_time));
	date_elements = ft_strsplit(date_time_string, ' ');
	time_elements = ft_strsplit(date_elements[TIME], ':');
	ft_putstr(date_elements[MONTH]);
	ft_putchar(' ');
	print_formatted_string_right(date_elements[DAY_OF_MONTH], 2);
	ft_putchar(' ');
	ft_putstr(time_elements[HOURS]);
	ft_putchar(':');
	ft_putstr(time_elements[MINUTES]);
//	ft_putchar(':');
//	ft_putstr(time_elements[SECONDS]);
	free(date_elements);
	free(time_elements);
}

void	print_link(t_node *file)
{
	char *link;

	link = ft_strnew(PATH_MAX);
	readlink(file->path, link, PATH_MAX - 1);
	ft_putstr(" -> ");
	ft_putstr(link);
	free(link);
}

void	print_long_version(t_node *file, t_print *width)
{
	t_stat	*st;

	st = file->details;
	print_file_type(st->st_mode);
	print_permissions(st->st_mode);
	ft_putchar(' ');
	print_formatted_number(st->st_nlink, width->nlink);
	ft_putchar(' ');
	print_owners(st, width->owner, width->group);
	ft_putstr("  ");
	print_formatted_number(st->st_size, width->size);
	ft_putchar(' ');
	print_date_and_time(st->st_mtime);
	ft_putchar(' ');
	ft_putstr(file->name);
	if (is_link(file))
		print_link(file);
}
