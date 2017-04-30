/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_options(int argc, char **argv, t_request *this)
{
	int count;

	count = 1;
	while (count < argc && argv[count][0] == '-')
	{
		set_option(argv[count][1], this);
		++count;
	}
	return (count);
}

void	set_option(char option, t_request *this)
{
	if (option == 'l')
		this->options->l = 1;
	else if (option == 'R')
		this->options->R = 1;
	else if (option == 'a')
		this->options->a = 1;
	else if (option == 'r')
		this->options->r = 1;
	else if (option == 't')
		this->options->t = 1;
	else
		illegal_option(option);
}

void	clear_options(t_args *options)
{
	//printf("CLEARING OPTIONS\n");
	options->l = 0;
	options->R = 0;
	options->a = 0;
	options->r = 0;
	options->t = 0;
}	
