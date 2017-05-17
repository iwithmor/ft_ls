/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   major_and_minor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_major_and_minor(t_node *file, t_print *width)
{
	int	dev_major;
	int	dev_minor;

	dev_major = major(file->details->st_rdev);
	dev_minor = minor(file->details->st_rdev);
	print_formatted_number(dev_major, width->major);
	ft_putchar(',');
	print_formatted_number(dev_minor, width->minor);
}