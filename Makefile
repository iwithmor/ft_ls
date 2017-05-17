# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/24 10:57:16 by iwithmor          #+#    #+#              #
#    Updated: 2017/04/24 10:57:16 by iwithmor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIB = ./libft/libft.a

SRC = main.c
SRC += new.c
SRC += errors.c
SRC += get.c
SRC += options.c
SRC += sort.c
SRC += print.c
SRC += is_type.c
SRC += add.c
SRC += compare.c
SRC += swap.c
SRC += path.c
SRC += print_long_version.c
SRC += permissions.c
SRC += format.c
SRC += spacing.c
SRC	+= blocks.c
SRC += print_recursive.c
SRC += verify.c
SRC += extended_attributes.c
SRC += major_and_minor.c
SRC += reverse.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
ADD_LIB = -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(ADD_LIB)

$(OBJ): $(LIB)
	gcc $(FLAGS) -I libft/ -c $(SRC)

$(LIB):
	make -C libft/

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all