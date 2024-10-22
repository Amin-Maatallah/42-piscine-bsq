# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 12:09:19 by lwillis           #+#    #+#              #
#    Updated: 2024/10/22 19:15:56 by amaatall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

# Defines where the source files are
SOURCES = srcs/main.c srcs/read_file.c srcs/str_utils.c srcs/parse_map.c srcs/map.c srcs/mock.c srcs/print_grid.c srcs/obstacles_grid.c srcs/test_square.c srcs/print_solved_map.c srcs/parse_legend.c

# Shortcut to do the same but with the object files
OBJECTS = $(SOURCES:c=o)

# Defines the compiler and its flags
CC = cc
#CFLAGS = -Wall -Wextra -Werror -I includes
CFLAGS = -I includes 

all: $(NAME)

# Puts the .o files into a library
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

# Builds the .o files. $@ = target name
$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(@:o=c) -o $@

# Deletes .o files
clean:
	rm -f $(OBJECTS)

# Deletes object files, then the output file
fclean: clean
	rm -f $(NAME)

# Rebuilds, so first deletes all then builds again
re: fclean all

# Tells Make that these commands don't build files with those names
.PHONY: all clean fclean re
