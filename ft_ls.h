/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "./libft/libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <limits.h>
#include <pwd.h>
#include <grp.h>
#include <langinfo.h>

typedef struct	stat t_stat;

typedef struct	s_args
{
	int			l;
	int			R;
	int			a;
	int			r;
	int			t;
}				t_args;

typedef struct		s_node
{
	char			*path;
	char			*name;
	t_stat			*details;
	int				file_count;
	struct	s_node	*sub;
	struct	s_node	*next;
}					t_node;

typedef struct	s_request
{
	t_args		*options;
	t_node		*files;
	int			file_count;
	int			arg_count;
}				t_request;

void		memory_error(void);
void		illegal_option(char c);
void		invalid_file(char *s);
void		ls_error(char *filename, char *error);

t_request	*new_request(void);
t_node		*new_file(char *filename, char *prefix);

int			get_options(int argc, char **argv, t_request *this);
void		get_files(int start, int end, char **argv, t_request *this);
void		get_directory_contents(t_node *directory);

void		add_file_to_request(t_node *new_file, t_request *this);
void		add_file_to_directory(t_node *file, t_node *directory);

void		set_path(t_node *file, char *prefix);
void		expand_path(t_node *file, t_node *directory);

int			get_options(int argc, char **argv, t_request *this);
void		set_option(char option, t_request *this);
void		clear_options(t_args *options);

void		sort(t_request *this);
void		sort_request_files(t_request *this);
void		sort_directory_files(t_node *directory, t_request *this);

t_node		*compare_and_swap(t_node *current, t_request *this);
t_node		*directory_compare_and_swap(t_node *f, t_node *d, t_request *this);

t_node		*swap_request_files(t_node *n1, t_node *n2, t_request *this);
t_node		*swap_directory_files(t_node *n1, t_node *n2, t_node *directory);

void		print(t_request *this);
void		print_files(t_request *this);
void		print_files_from_directory(t_node *directory, t_request *this);
void		print_directory_contents(t_node *directory, t_request *this);
void		print_directories(t_request *this);

void		print_long_version(t_node *file);
void		print_permissions(mode_t mode);

void		print_formatted_number(int number, int width);
void		print_formatted_string(char *str, int width);

int			is_link(t_node *file);
int			is_directory(t_node *file);
int			is_link_to_directory(t_node *file);

#endif
