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

void	print_owners(t_stat *details)
{
	struct passwd  *user;
	struct group   *group;

	user = getpwuid(details->st_uid);
	group = getgrgid(details->st_gid);
	if (user)
		print_formatted_string(user->pw_name, 12);
	else
		print_formatted_number(details->st_uid, 12);
	ft_putchar(' ');
	if (group)
		print_formatted_string(group->gr_name, 8);
	else
		print_formatted_number(details->st_gid, 8);
}

void	print_number_of_links(int number_of_links)
{
	print_formatted_number(number_of_links, 4);
}

void	print_date_and_time(time_t modification_time)
{
	struct tm	*m_time;
	char		date[256];

	m_time = localtime(&modification_time);
	strftime(date, sizeof(date), nl_langinfo(D_T_FMT), m_time);
	ft_putstr(date);
}

void	print_long_version(t_node *file)
{
	print_file_type(file->details->st_mode);
	print_permissions(file->details->st_mode);
	ft_putchar(' ');
	print_number_of_links(file->details->st_nlink);
	ft_putchar(' ');
	print_owners(file->details);
	ft_putchar(' ');
	//print_size();
	print_date_and_time(file->details->st_mtime);
	ft_putchar(' ');
	ft_putstr(file->name);
}
