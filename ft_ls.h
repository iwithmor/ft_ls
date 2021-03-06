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

# include "./libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <fcntl.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <time.h>
# include <limits.h>
# include <pwd.h>
# include <grp.h>
# include <langinfo.h>

# define DAY_OF_WEEK	0
# define MONTH			1
# define DAY_OF_MONTH	2
# define TIME			3
# define YEAR			4

# define HOURS			0
# define MINUTES		1
# define SECONDS		2

typedef struct stat		t_stat;

typedef struct			s_invalid
{
	char				*name;
	struct s_invalid	*next;
}						t_invalid;

typedef struct			s_print
{
	int					nlink;
	int					owner;
	int					group;
	int					major;
	int					minor;
	int					size;
}						t_print;

typedef struct			s_args
{
	int					l;
	int					big_r;
	int					a;
	int					r;
	int					t;
}						t_args;

typedef struct			s_node
{
	char				*path;
	char				*name;
	t_stat				*details;
	t_print				*width;
	int					file_count;
	struct s_node		*sub;
	struct s_node		*next;
}						t_node;

typedef struct			s_request
{
	t_args				*options;
	t_node				*files;
	t_invalid			*err_files;
	int					file_count;
	int					arg_count;
	int					directory_count;
	int					err_count;
	t_print				*width;
}						t_request;

void					memory_error(void);
void					illegal_option(char c);
void					invalid_file(char *s);
void					ls_error(char *filename, char *error);
void					print_invalid_files(t_request *this);
t_request				*new_request(void);
t_node					*new_file(char *filename, char *prefix);
t_node					*copy_file(char *file_name, char *file_path);
int						get_options(int argc, char **argv, t_request *this);
void					get_files(int strt, int end, char **argv, t_request *t);
void					get_directory_contents(t_node *directory, t_request *t);
void					add_file_to_request(t_node *new_file, t_request *this);
void					add_file_to_directory(t_node *file, t_node *directory);
void					add_file_as_invalid(char *str, t_request *this);
void					set_path(t_node *file, char *prefix);
char					*get_parent_path(t_node *file);
char					*get_linked_path(t_node *directory);
int						get_options(int argc, char **argv, t_request *this);
void					set_option(char option, t_request *this);
void					clear_options(t_args *options);
void					sort(t_request *this);
void					sort_request_files(t_request *this);
void					sort_directory_files(t_node *dir, t_request *this);
void					sort_invalid_files(t_request *this);
t_node					*compare_and_swap(t_node *current, t_request *this);
t_node					*dir_comp_and_swap(t_node *f, t_node *d, t_request *t);
t_invalid				*compare_and_swap_err(t_invalid *f, t_request *t);
t_node					*swap_request_files(t_node *a, t_node *b, t_request *t);
t_node					*swap_dir_files(t_node *a, t_node *b, t_node *dir);
t_invalid				*swap_err(t_invalid *a, t_invalid *b, t_request *t);
void					print(t_request *this);
void					print_files(t_request *this);
void					print_files_from_directory(t_node *dir, t_request *t);
void					print_directory_contents(t_node *dir, t_request *this);
void					print_directories(t_request *this);
void					print_long_version(t_node *file, t_print *width);
void					print_permissions(t_node *file);
int						has_permission(int mode, int mask);
int						has_extended_attributes(t_node *file);
void					print_formatted_number(int number, int width);
void					print_formatted_string_left(char *str, int width);
void					print_formatted_string_right(char *str, int width);
void					print_directory_name(t_node *directory, t_request *t);
void					print_r_directory_name(t_node *d, t_request *t, int i);
void					print_r_directories(t_request *this);
void					print_recursive(t_node *dir, t_request *t, int i);
char					file_type(mode_t st_mode);
int						is_link(t_node *file);
int						is_directory(t_node *file);
int						is_link_to_directory(t_node *file);
int						is_device(t_node *file);
int						is_current_year(char *year);
void					set_spacing_for_request(t_request *this);
void					set_spacing_for_directory(t_node *dir, t_request *this);
int						total_blocks(t_node *directory, t_request *this);
void					ls_recursive(t_node *directory, t_request *this, int i);
void					verify_arguments(char **args, int start, int end);
void					print_major_and_minor(t_node *file, t_print *width);
void					print_block_total(t_node *file, t_request *this);
void					reverse_directory_files(t_node *directory);
void					reverse_files(t_request *this);
long					time_cmp(t_node *n1, t_node *n2);

#endif
