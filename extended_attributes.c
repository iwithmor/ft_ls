/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_attributes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	has_extended_attributes(t_node *file)
{
	int		count;

	count = listxattr(file->path, NULL, 0, XATTR_NOFOLLOW);
	if (count > 0)
		return (1);
	return (0);
}

int	has_acl_xattr(t_node *file)
{
	acl_t	acl;

	acl = acl_get_file(file->path, ACL_TYPE_ACCESS);
	if (acl)
		return (1);
	return (0);
}
