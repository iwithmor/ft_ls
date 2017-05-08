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
	int i;

	count = 1;
	while (count < argc && argv[count][0] == '-')
	{
		i = ft_strlen(argv[count]);
		if (i == 1)
			break ;
		while (--i >= 1)
			set_option(argv[count][i], this, i);
		++count;
	}
	return (count);
}

int		valid_unsupported_option(char c)
{
	if (c == '1' || c == 'A' || c == '@' || c == 'B' || c == 'b')
		return (1);
	if (c == 'C' || c == 'c' || c == 'd' || c == 'e' || c == 'F')
		return (1);
	if (c == 'f' || c == 'G' || c == 'g' || c == 'H' || c == 'h')
		return (1);
	if (c == 'i' || c == 'k' || c == 'L' || c == 'm' || c == 'n')
		return (1);
	if (c == 'O' || c == 'o' || c == 'P' || c == 'p' || c == 'q')
		return (1);
	if (c == 'S' || c == 's' || c == 'T' || c == 'U' || c == 'u')
		return (1);
	if (c == 'v' || c == 'W' || c == 'w' || c == 'x')
		return (1);
	else
		return (0);
}

void	set_option(char option, t_request *this, int i)
{
	if (i == 1 && option == '-')
		return ;
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
	else if (valid_unsupported_option(option))
		return ;
	else
		illegal_option(option);
}

void	clear_options(t_args *options)
{
	options->l = 0;
	options->R = 0;
	options->a = 0;
	options->r = 0;
	options->t = 0;
}	
