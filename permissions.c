/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// diff <(ls -lR /usr/bin) <(./ft_ls -lR /usr/bin)

int	has_permission(int mode, int mask)
{
	return ((mode & mask) == mask);
}

void	print_user_permission(mode_t mode)
{
	if (has_permission(mode, S_IRUSR))
		ft_putchar('r');
	else
		ft_putchar('-');
	if (has_permission(mode, S_IWUSR))
		ft_putchar('w');
	else
		ft_putchar('-');
	if (has_permission(mode, S_ISUID))
	{
		if (has_permission(mode, S_IXUSR))
			ft_putchar('s');
		else
			ft_putchar('S');
	}
	else if (has_permission(mode, S_IXUSR))
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	print_group_permission(mode_t mode)
{
	if (has_permission(mode, S_IRGRP))
		ft_putchar('r');
	else
		ft_putchar('-');
	if (has_permission(mode, S_IWGRP))
		ft_putchar('w');
	else
		ft_putchar('-');
	if (has_permission(mode, S_ISGID))
	{
		if (has_permission(mode, S_IXGRP))
			ft_putchar('s');
		else
			ft_putchar('S');
	}
	else if (has_permission(mode, S_IXGRP))
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	print_other_permission(mode_t mode)
{
	if (has_permission(mode, S_IROTH))
		ft_putchar('r');
	else
		ft_putchar('-');
	if (has_permission(mode, S_IWOTH))
		ft_putchar('w');
	else
		ft_putchar('-');
	if (has_permission(mode, S_ISVTX))
	{
		if (has_permission(mode, S_IXOTH))
			ft_putchar('t');
		else
			ft_putchar('T');
	}
	else if (has_permission(mode, S_IXOTH))
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	print_permissions(mode_t mode)
{
	print_user_permission(mode);
	print_group_permission(mode);
	print_other_permission(mode);
	//	TO DO:
	ft_putchar(' ');
//	if (...)
//		ft_putchar('@');
//	else if (...)
//		ft_putchar('+');
//	else
//		ft_putchar(' ');
}
